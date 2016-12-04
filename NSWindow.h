//
//  NSWindow.h
//  NoFavicons
//

#ifndef NoFavicons_NSWindow_h
#define NoFavicons_NSWindow_h

#import "ThemeProvider.h"

@interface NSWindow (ThemeProvider)
- (BOOL)hasDarkTheme;
- (BOOL)inIncognitoModeWithSystemTheme;
- (BOOL)inIncognitoMode;
- (struct CGPoint)themeImagePositionForAlignment:(int)arg1;
- (unsigned long long)themedWindowStyle;
- (const ui::ThemeProvider *)themeProvider;
@end

#endif
