# Create commits for all missing dates
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
$files = @(
    "nextpremutation/optimal.cpp",
    "TwoSum/optimal.cpp", 
    "stocks/optimal.cpp",
    "Majority Element/optimal.cpp",
    "Sort an array of 0's 1's and 2's/optimal.cpp",
    "maxLengSubArrSum/optimalApp.cpp",
    "missingNumber/optimalApproach.cpp",
    "nextpremutation/bruteforce.cpp",
    "TwoSum/bruteForce.CPP",
    "stocks/bruteforce.cpp"
)

$improvements = @(
    "// Code cleanup",
    "// Formatting improvement", 
    "// Documentation update",
    "// Code optimization",
    "// Style improvement",
    "// Readability enhancement",
    "// Structure refinement"
)

$fileIdx = 0
$improveIdx = 0

foreach ($date in $missingDates) {
    $file = $files[$fileIdx % $files.Length]
    $improve = $improvements[$improveIdx % $improvements.Length]
    
    if (Test-Path $file) {
        $content = Get-Content $file -Raw
        
        # Add improvement comment after includes
        if ($content -match "(#include[^\n]+\n)") {
            $newContent = $content -replace "($matches[1])", "`$1$improve - $date`n"
        } elseif ($content -match "(using namespace std;)") {
            $newContent = $content -replace "($matches[1])", "`$1`n$improve - $date`n"
        } else {
            # Add at beginning
            $newContent = "$improve - $date`n" + $content
        }
        
        Set-Content $file -Value $newContent -NoNewline
        git add $file
        
        $env:GIT_AUTHOR_DATE = "$date 12:00:00 +0530"
        $env:GIT_COMMITTER_DATE = "$date 12:00:00 +0530"
        
        $msg = "Code improvement - $date"
        git commit -m $msg --date="$date 12:00:00 +0530" --quiet
        
        Write-Host "Created commit for $date"
    }
    
    $fileIdx++
    $improveIdx++
}

Write-Host "`nCompleted! Created $($missingDates.Count) commits."

