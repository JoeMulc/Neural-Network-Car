// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class CMP_304_COURSEWORK_EditorTarget : TargetRules
{
	public CMP_304_COURSEWORK_EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "CMP_304_COURSEWORK_" } );
	}
}
