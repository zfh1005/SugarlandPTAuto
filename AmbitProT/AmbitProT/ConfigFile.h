
#pragma once

class CConfigFile
{
public:
	CConfigFile(void);
public:
	~CConfigFile(void);


public:
#ifdef _UNICODE
	int PerformParse(CString FileName);
#else
    int PerformParse(char * pFileName);
	int ParserGetPara(char *pDesBUFF, char *pTagBuff, char *pRtnConBUFF, UINT RtnConBUFFLen);
	
	int GetValidLine(char *pDesBUFF,char *pRtnConBUFF, int RtnSize);
	/*this function is copy some character from string to other case one spec ch was happen*/
	int CopyCaseStr(char *pDst, int DstLen, const char *pSrc, char caseCH);
	int GetSegment();
#endif

private:
#ifdef _UNICODE	
	int ReadFileToMem(CString FileName);
	CString FileContent;
	int GetSector();
	int GetSystemConfigInfo(wchar_t * pBuf, int bufL);
#else	
	unsigned char HEXConvert (unsigned char ucHEX);
    int StrHEXConvert(char *psrc, int iCovertNum,DWORD *pRtn);
    char *HexToStrConvert(char *PtrRtn, unsigned int  uiHex);//convert a ui to char
	char SegmentBuf[5000];
    int FindPaketSEflag(char *PBuf, size_t DataLen);
	int GetTRData();
	
	int ReadFileToMem(char *pfile_name);
		int GetItem();
    int LegalJudge();
	int GetParaContent(char *pBuf, UINT Len);
    int JudgeStr(char *pBuf);

	char *pContentBuf;
	int TestItemSequence;
	typedef struct MerPaket
	{
		char *pData;
		int DataLen;

	}MER_PAKET;
   list<MER_PAKET> MPaketList;

	typedef struct STnEDFlag
	{
		int StFlagIndex;
		int EdFlagIndex;
	}STNED_FLAG;

	STNED_FLAG StNeDFlag[500];
#endif	

};
