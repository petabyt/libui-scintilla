#ifdef __cplusplus
extern "C" {
#endif

typedef struct uiScintilla uiScintilla;
_UI_EXTERN void uiScintillaGetRange(uiScintilla *s, unsigned int start, unsigned int end, char *text);
_UI_EXTERN void uiScintillaSetText(uiScintilla *s, const char *text, unsigned int len);
_UI_EXTERN void uiScintillaAppend(uiScintilla *s, const char *text);
_UI_EXTERN unsigned int uiScintillaGetLength(uiScintilla *s);
_UI_EXTERN uiScintilla *uiNewScintilla();
_UI_EXTERN char *uiScintillaText(uiScintilla *s);
_UI_EXTERN uintptr_t uiScintillaSendMessage(uiScintilla *s, uint32_t code, uintptr_t w, uintptr_t l);

#ifdef __cplusplus
}
#endif
