# Library API functions testing script
#
# Version: 20161106

$ExitSuccess = 0
$ExitFailure = 1
$ExitIgnore = 77

$TestPrefix = Split-Path -path ${Pwd}.Path -parent
$TestPrefix = Split-Path -path ${TestPrefix} -leaf
$TestPrefix = ${TestPrefix}.Substring(3)

$TestFunctions = "base16_stream base32_stream base64_stream_copy_from base64_stream_copy_to error support unicode_character_copy_from unicode_character_copy_to utf16_stream_copy_from utf16_string_copy_from utf32_stream_copy_from utf32_string_copy_from utf7_stream_copy_from utf8_stream_copy_from utf8_string_copy_from"
$TestFunctions = ${TestFunctions} -split " "

$TestToolDirectory = "..\msvscpp\Release"

Function TestAPIFunction
{
	param( [string]$TestFunction, [string[]]$Options, [string]$Profile )

	$TestDescription = "Testing API functions: ${TestFunction}"
	$TestExecutable = "${TestToolDirectory}\${TestPrefix}_test_${TestFunction}.exe"

	$Output = Invoke-Expression ${TestExecutable}
	$Result = ${LastExitCode}

	If (${Result} -ne ${ExitSuccess})
	{
		Write-Host ${Output} -foreground Red
	}
	Write-Host "${TestDescription} " -nonewline

	If (${Result} -ne ${ExitSuccess})
	{
		Write-Host " (FAIL)"
	}
	Else
	{
		Write-Host " (PASS)"
	}
	Return ${Result}
}

If (-Not (Test-Path ${TestToolDirectory}))
{
	$TestToolDirectory = "..\vs2010\Release"
}
If (-Not (Test-Path ${TestToolDirectory}))
{
	Write-Host "Missing test tool directory." -foreground Red

	Exit ${ExitFailure}
}

$Result = ${ExitIgnore}

Foreach (${TestFunction} in ${TestFunctions})
{
	$Result = TestAPIFunction ${TestFunction}

	If (${Result} -ne ${ExitSuccess})
	{
		Break
	}
}

Exit ${Result}

