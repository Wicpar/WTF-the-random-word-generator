// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "WTF.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API UWTF : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "WTF Random Words")
		static FString GenerateWord(int32 minLetters, int32 maxLetters, FString prefix, FString suffix);

private:
	static TCHAR getNextRandomAuthorizedLetter(FString word);
	static bool isLong(TCHAR c);
	static bool isShort(TCHAR c);
	static bool isVocal(TCHAR c);
	static TCHAR getRandomVocal(TCHAR lastchar);
	static TCHAR getRandomShort(TCHAR lastchar);
	static TCHAR getRandomLong(TCHAR lastchar);
	static bool isRepeatable(TCHAR c);
	static TArray<TCHAR> getVocals();
	static TArray<TCHAR> getShorts();
	static TArray<TCHAR> getLongs();
	static TArray<TCHAR> getRepeatables();

	static TArray<TCHAR> Vocals;
	static TArray<TCHAR> Shorts;
	static TArray<TCHAR> Longs;
	static TArray<TCHAR> Repeatables;
};
