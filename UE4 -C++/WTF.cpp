// Fill out your copyright notice in the Description page of Project Settings.

#include "testProject.h"
#include "WTF.h"

FString UWTF::GenerateWord(int32 minLetters, int32 maxLetters, FString prefix = "", FString suffix = ""){

	if (minLetters < 0){
		minLetters = 0;
	}
	if (maxLetters < minLetters){
		maxLetters = minLetters;
	}
	if (maxLetters < 0){
		maxLetters = 0;
	}
	int32 l = 0;
	int32 r = maxLetters - minLetters;
	if (r > 0)
		l = FMath::RandRange(0,r-1);
	else
		l = minLetters;
	l += minLetters;
	while (prefix.Len() < l)
	{
		prefix += getNextRandomAuthorizedLetter(prefix);
	}
	prefix.RemoveAt(prefix.Len() - suffix.Len(), suffix.Len());
	prefix += suffix;
	return prefix;
}

TCHAR UWTF::getNextRandomAuthorizedLetter(FString word){

	if (word.IsEmpty())
	{
		switch (FMath::RandRange(0, 2))
		{
		case 0:
			return getRandomVocal(' ');
		case 1:
			return getRandomShort(' ');
		case 2:
			return getRandomLong(' ');
		}
	}
	else
	{
		TCHAR lastchar = word[word.Len() - 1];
		if (lastchar == 'q')
		{
			return getRandomVocal(lastchar);
		}else
		if (word.Len() < 2)
		{
			if (isShort(lastchar))
			{
				switch (FMath::RandRange(0, 1))
				{
				case 0:
					return getRandomVocal(lastchar);
				case 1:
					return getRandomLong(lastchar);
				}
			}
			else
			{
				switch (FMath::RandRange(0, 2))
				{
				case 0:
					return getRandomVocal(lastchar);
				case 1:
					return getRandomShort(lastchar);
				case 2:
					return getRandomLong(lastchar);
				}
			}
		}
		else
		{
			TCHAR prelastchar = word[word.Len() - 2];
			if (isVocal(prelastchar))
			{
				if (isShort(lastchar))
				{
					switch (FMath::RandRange(0, 1))
					{
					case 0:
						return getRandomVocal(lastchar);
					case 1:
						return getRandomLong(lastchar);
					}
				}
				else if (isLong(lastchar))
				{
					switch (FMath::RandRange(0, 2))
					{
					case 0:
						return getRandomVocal(lastchar);
					case 1:
						return getRandomShort(lastchar);
					case 2:
						return getRandomLong(lastchar);
					}
				}
				else
				{
					switch (FMath::RandRange(0, 1))
					{
					case 0:
						return getRandomShort(lastchar);
					case 1:
						return getRandomLong(lastchar);
					}
				}
			}
			else
			{
				if (isShort(lastchar) || isLong(lastchar))
				{
					return getRandomVocal(lastchar);
				}
				else
				{
					switch (FMath::RandRange(0, 2))
					{
					case 0:
						return getRandomVocal(lastchar);
					case 1:
						return getRandomShort(lastchar);
					case 2:
						return getRandomLong(lastchar);
					}
				}
			}
		}
	}
	return '?';
}


bool UWTF::isLong(TCHAR c){
	return Longs.Contains(c);
}
bool UWTF::isShort(TCHAR c){
	return Shorts.Contains(c);
}
bool UWTF::isVocal(TCHAR c){
	return Vocals.Contains(c);
}
TCHAR UWTF::getRandomVocal(TCHAR lastchar){

	if (lastchar == ' ')
	{
		return Vocals[FMath::RandRange(0, Vocals.Num() - 1)];
	}else

	if (isVocal(lastchar))
	{
		TCHAR c = Vocals[FMath::RandRange(0, Vocals.Num() - 1)];
		if (c == lastchar)
		{
			if (isRepeatable(c))
			{
				return c;
			}
			else
			{
				return getRandomVocal(lastchar);
			}
		}
		return c;
	}
	else{
		return Vocals[FMath::RandRange(0, Vocals.Num() - 1)];
	}
}
TCHAR UWTF::getRandomShort(TCHAR lastchar){
	if (lastchar == ' ')
	{
		return Shorts[FMath::RandRange(0, Shorts.Num() - 1)];
	}else
	if (isVocal(lastchar))
	{
		TCHAR c = Shorts[FMath::RandRange(0, Shorts.Num() - 1)];
		if (c == lastchar)
		{
			if (isRepeatable(c))
			{
				return c;
			}
			else
			{
				return getRandomShort(lastchar);
			}
		}
		return c;
	}
	else{
		return Shorts[FMath::RandRange(0, Shorts.Num() - 1)];
	}
}
TCHAR UWTF::getRandomLong(TCHAR lastchar){
	if (lastchar == ' ')
	{
		return Longs[FMath::RandRange(0, Longs.Num() - 1)];
	}else if (isVocal(lastchar))
	{
		TCHAR c = Longs[FMath::RandRange(0, Longs.Num() - 1)];
		if (c == lastchar)
		{
			if (isRepeatable(c))
			{
				return c;
			}
			else
			{
				return getRandomLong(lastchar);
			}
		}
		return c;
	}
	else{
		return Longs[FMath::RandRange(0, Longs.Num() - 1)];
	}
}

bool UWTF::isRepeatable(TCHAR c)
{
	if (Repeatables.Contains(c)){
		return true;
	}
	else{
		return false;
	}
}


TArray<TCHAR> UWTF::getVocals(){
	TArray<TCHAR> t;
	t.Add('a');
	t.Add('e');
	t.Add('i');
	t.Add('o');
	t.Add('u');
	t.Add('y');
	return t;
}
TArray<TCHAR> UWTF::getShorts(){
	TArray<TCHAR> t;
	t.Add('t');
	t.Add('p');
	t.Add('q');
	t.Add('d');
	t.Add('g');
	t.Add('k'); 
	t.Add('x'); 
	t.Add('c'); 
	t.Add('b');
	return t;
}
TArray<TCHAR> UWTF::getLongs(){
	TArray<TCHAR> t;
	t.Add('z');
	t.Add('r');
	t.Add('s');
	t.Add('f');
	t.Add('h');
	t.Add('j');
	t.Add('l');
	t.Add('m');
	t.Add('w');
	t.Add('v');
	t.Add('n');
	return t;
}

TArray<TCHAR> UWTF::getRepeatables(){
	TArray<TCHAR> t;
	t.Add('a');
	t.Add('z');
	t.Add('e');
	t.Add('r');
	t.Add('t');
	t.Add('o');
	t.Add('p');
	t.Add('s');
	t.Add('d');
	t.Add('f');
	t.Add('g');
	t.Add('l');
	t.Add('m');
	t.Add('c');
	t.Add('n');
	return t;
}


TArray<TCHAR> UWTF::Vocals = getVocals();
TArray<TCHAR> UWTF::Shorts = getShorts();
TArray<TCHAR> UWTF::Longs = getLongs();
TArray<TCHAR> UWTF::Repeatables = getRepeatables();

