#ifndef _TKHOOKLIB_H
#define _TKHOOKLIB_H

#define SOINFO_NAME_LEN 128

#define HOOK_SUCCESS 0
#define HOOK_FAILED -1

typedef struct _HookStruct{
	char SOName[SOINFO_NAME_LEN];
	char FunctionName[SOINFO_NAME_LEN];
	void *NewFunc;
	void *OldFunc;
	void *occPlace;
}HookStruct;

#ifdef __cplusplus
extern "C" {
#endif

void TK_UnHookExportFunction(HookStruct *pHookStruct);

void TK_UnHookImportFunction(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Hook libfoo.so Import Function: puts
**	HookStruct HookPara;
**  strncpy(HookPara.SOName, "libfoo.so", strlen("libfoo.so"));
**	strncpy(HookPara.FunctionName, "puts", strlen("puts"));
**	HookPara.NewFunc = myputs;
**	TK_HookImportFunction(&HookPara);
*/
int TK_HookImportFunction(HookStruct *pHookStruct);
typedef int  (*TK_HookImportFunction_t)(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Hook libc.so Export Function: puts
**	HookStruct HookPara;
**  strncpy(HookPara.SOName, "libc.so", strlen("libc.so"));
**	strncpy(HookPara.FunctionName, "puts", strlen("puts"));
**	HookPara.NewFunc = myputs;
**	TK_HookExportFunction(&HookPara);
*/
int TK_HookExportFunction(HookStruct *pHookStruct);
typedef int  (*TK_HookExportFunction_t)(HookStruct *pHookStruct);

/*
**  Return: HOOK_SUCCESS or HOOK_FAILED
**	Example: 	Inline Hook libc.so Function: puts
**	void* OldFunc = NULL;
**	TK_InlineHookFunction(puts, myputs, &OldFunc);
*/
int TK_InlineHookFunction(void *TargetFunc, void *NewFunc, void** OldFunc);
typedef int  (*TK_InlineHookFunction_t)(void *TargetFunc, void *NewFunc, void **OldFunc);

#ifdef __cplusplus
};
#endif

#endif