# Fill missing dates with empty commits
$startDate = Get-Date "2025-11-09"
$endDate = Get-Date "2026-01-09"

# Get existing commit dates
$commitDates = @{}
git log --all --format="%ai" --date=short | ForEach-Object { 
    $date = ($_ -split ' ')[0]
    $commitDates[$date] = $true 
}

# Find missing dates
$missingDates = @()
$currentDate = $startDate
while ($currentDate -le $endDate) {
    $dateStr = $currentDate.ToString("yyyy-MM-dd")
    if (-not $commitDates.ContainsKey($dateStr)) {
        $missingDates += $dateStr
    }
    $currentDate = $currentDate.AddDays(1)
}

Write-Host "Creating $($missingDates.Count) empty commits for missing dates..."

foreach ($date in $missingDates) {
    $env:GIT_AUTHOR_DATE = "$date 12:00:00 +0530"
    $env:GIT_COMMITTER_DATE = "$date 12:00:00 +0530"
    git commit --allow-empty -m "Daily commit - $date" --date="$date 12:00:00 +0530" --quiet
    Write-Host "Created commit for $date"
}

Write-Host "`nCompleted! Created $($missingDates.Count) commits."

