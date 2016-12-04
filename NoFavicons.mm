#import "NoFavicons.h"
#import "TabView.h"
#import "TabView+Fix.h"
#import <objc/objc-class.h>

@implementation NoFavicons

+ (void) load
{
    NSLog(@"NoFavicons loading");
    [self swizzleBookmarkCellWithoutImage];
    NSLog(@"NoFavicons installed");
}

+ (void) swizzleBookmarkCellWithoutImage
{
    Class klass = NSClassFromString(@"TabView");
    SEL oldSelector = @selector(backgroundColorForSelected:);
    SEL newSelector = @selector(XXXbackgroundColorForSelected:);
    [self swizzle:oldSelector with: newSelector inClass:klass];
}

+ (void) swizzle:(SEL)oldSelector with:(SEL)newSelector inClass:(Class)klass 
{
    Method oldMethod = class_getInstanceMethod(klass, oldSelector);
    Method newMethod = class_getInstanceMethod(klass, newSelector);
    
    if(class_addMethod(klass, oldSelector, method_getImplementation(newMethod), method_getTypeEncoding(newMethod)))
    {
        NSLog(@"Creating new implementation for setBookmarkCellText:image: and overriding setBookmarkCellText:withoutImage:");
        class_replaceMethod(klass, newSelector, method_getImplementation(oldMethod), method_getTypeEncoding(oldMethod));
    } 
    else
    {
        NSLog(@"Exchanging implementations for setBookmarkCellText:image: and setBookmarkCellText:withoutImage:");
        method_exchangeImplementations(oldMethod, newMethod);        
    }
}

@end
