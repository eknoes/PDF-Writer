/*
   Source File : FreeTypeWrapper.h


   Copyright 2011 Gal Kahana PDFWriter

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   
*/
#pragma once

#include "EStatusCode.h"

#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace std;

class FreeTypeWrapper
{
public:
	FreeTypeWrapper(void);
	~FreeTypeWrapper(void);

	FT_Face NewFace(const string& inFilePath,FT_Long inFontIndex = 0);
	FT_Face NewFace(const string& inFilePath,const string& inSecondaryFilePath,FT_Long inFontIndex = 0);
	FT_Face NewFace(const wstring& inFilePath,FT_Long inFontIndex = 0);
	FT_Face NewFace(const wstring& inFilePath,const wstring& inSecondaryFilePath,FT_Long inFontIndex = 0);
	FT_Error DoneFace(FT_Face ioFace);

	FT_Library operator->();
	operator FT_Library() const;

private:

	FT_Library mFreeType;

	FT_Stream CreateFTStreamForPath(const wstring& inFilePath);
	EStatusCode FillOpenFaceArgumentsForWideString(const wstring& inFilePath, FT_Open_Args& ioArgs);
	void CloseOpenFaceArgumentsStream(FT_Open_Args& ioArgs);

};