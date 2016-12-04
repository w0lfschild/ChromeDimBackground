#import <CommonCrypto/CommonDigest.h>
#import "TabView+Fix.h"
#import "NSWindow.h"

#define IDR_THEME_TOOLBAR 0
#define IDR_THEME_TAB_BACKGROUND 0
#define IDR_THEME_TAB_BACKGROUND_INACTIVE 0
#define IDR_THEME_TOOLBAR_INACTIVE 0

@implementation NSView (TabViewFix)

- (NSColor*) XXXbackgroundColorForSelected:(bool)selected {
    
    // Themes don't have an inactive image so only look for one if there's no
    // theme.
    bool active = [[self window] isMainWindow];
    
    if (active)
    {
        return [self XXXbackgroundColorForSelected: selected];
    }
    else
    {
        return [self XXXbackgroundColorForSelected: true];
    }
}

@end
