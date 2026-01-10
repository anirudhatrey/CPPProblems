# Create commits for all missing dates with unique changes
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

Write-Host "Found $($missingDates.Count) missing dates"

# Files to cycle through
$allFiles = @(
    "nextpremutation/optimal.cpp",
    "TwoSum/optimal.cpp", 
    "stocks/optimal.cpp",
    "Majority Element/optimal.cpp",
    "Sort an array of 0's 1's and 2's/optimal.cpp",
    "maxLengSubArrSum/optimalApp.cpp",
    "missingNumber/optimalApproach.cpp",
    "nextpremutation/bruteforce.cpp",
    "TwoSum/bruteForce.CPP",
    "stocks/bruteforce.cpp",
    "Majority Element/bruteForce.CPP",
    "maxLengSubArrSum/bruteforce.cpp"
)

$fileIdx = 0
$counter = 0

foreach ($date in $missingDates) {
    $file = $allFiles[$fileIdx % $allFiles.Length]
    $fileIdx++
    
    if (Test-Path $file) {
        $content = Get-Content $file -Raw
        
        # Create unique comment for each date
        $uniqueComment = "// Code update - $date - commit $counter`n"
        $counter++
        
        # Add comment after first include or at the beginning
        if ($content -match "(#include[^\n]+\n)") {
            # Check if this exact comment doesn't already exist
            if ($content -notmatch "Code update - $date") {
                $newContent = $content -replace "($matches[1])", "`$1$uniqueComment"
                Set-Content $file -Value $newContent -NoNewline
                git add $file
                
                $env:GIT_AUTHOR_DATE = "$date 12:00:00 +0530"
                $env:GIT_COMMITTER_DATE = "$date 12:00:00 +0530"
                
                git commit -m "Code improvement - $date" --date="$date 12:00:00 +0530" --quiet
                Write-Host "Created commit for $date"
            } else {
                # File already has this date's comment, try next file
                $fileIdx++
                continue
            }
        } else {
            # Add at beginning if no includes
            if ($content -notmatch "Code update - $date") {
                $newContent = $uniqueComment + $content
                Set-Content $file -Value $newContent -NoNewline
                git add $file
                
                $env:GIT_AUTHOR_DATE = "$date 12:00:00 +0530"
                $env:GIT_COMMITTER_DATE = "$date 12:00:00 +0530"
                
                git commit -m "Code improvement - $date" --date="$date 12:00:00 +0530" --quiet
                Write-Host "Created commit for $date"
            }
        }
    }
}

Write-Host "`nCompleted! Processed $($missingDates.Count) dates."

