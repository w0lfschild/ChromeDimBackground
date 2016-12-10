@import AppKit;

#import "ZKSwizzle.h"

@interface ChromeDimBackground : NSObject
@end

@implementation ChromeDimBackground
+ (void) load
{
    NSLog(@"ChromeDimBackground loading");
    ZKSwizzle(wb_TabView, TabView);
    NSLog(@"ChromeDimBackground installed");
}
@end

@interface wb_TabView : NSView
- (id)backgroundColorForSelected:(bool)arg1;
@end

@implementation wb_TabView
- (id)backgroundColorForSelected:(bool)arg1 {
    if ([[self window] isMainWindow])
        return ZKOrig(id, arg1);
    else
        return ZKOrig(id, true);
}
@end
