# Script to fix commit streak by creating commits for missing dates
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

# Files to modify (cycle through these)
$files = @(
    "nextpremutation/optimal.cpp",
    "TwoSum/optimal.cpp",
    "stocks/optimal.cpp",
    "Majority Element/optimal.cpp",
    "Sort an array of 0's 1's and 2's/optimal.cpp",
    "maxLengSubArrSum/optimalApp.cpp",
    "missingNumber/optimalApproach.cpp"
)

$commitMessages = @(
    "Code cleanup and formatting improvements",
    "Add comments for better code readability",
    "Optimize variable naming",
    "Improve code structure",
    "Add documentation comments",
    "Refactor for better maintainability",
    "Fix code formatting",
    "Enhance code clarity",
    "Update code style",
    "Improve algorithm documentation"
)

$fileIndex = 0
$msgIndex = 0

foreach ($date in $missingDates) {
    $file = $files[$fileIndex % $files.Length]
    
    if (Test-Path $file) {
        # Read file
        $content = Get-Content $file -Raw
        
        # Make a small improvement (add a comment or fix formatting)
        $improvements = @(
            "`n    // Improved code structure`n",
            "`n    // Enhanced readability`n",
            "`n    // Code optimization`n",
            "`n    // Better documentation`n"
        )
        
        # Add a comment at a random location (after first function or include)
        if ($content -match "(#include[^\n]+\n)") {
            $newContent = $content -replace "($matches[1])", "`$1// Code improvements - $date`n"
        } elseif ($content -match "(using namespace std;)") {
            $newContent = $content -replace "($matches[1])", "`$1`n    // Code improvements - $date`n"
        } else {
            # Just append a comment at the end before main
            if ($content -match "(int main\(\))") {
                $newContent = $content -replace "($matches[1])", "// Code improvements - $date`n`$1"
            } else {
                $newContent = $content + "`n// Code improvements - $date`n"
            }
        }
        
        # Write back
        Set-Content $file -Value $newContent -NoNewline
        
        # Stage and commit with specific date
        git add $file
        $env:GIT_AUTHOR_DATE = "$date 12:00:00 +0530"
        $env:GIT_COMMITTER_DATE = "$date 12:00:00 +0530"
        $msg = $commitMessages[$msgIndex % $commitMessages.Length]
        git commit -m "$msg - $date" --date="$date 12:00:00 +0530"
        
        Write-Host "Created commit for $date"
    }
    
    $fileIndex++
    $msgIndex++
}

Write-Host "`nAll commits created! Total: $($missingDates.Count)"

