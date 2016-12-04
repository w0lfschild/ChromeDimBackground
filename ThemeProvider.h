//
//  Theme_Provider.h
//  Swizzler
//

#ifndef Swizzler_Theme_Provider_h
#define Swizzler_Theme_Provider_h

@class NSColor;
@class NSGradient;
@class NSImage;

namespace base {
    class RefCountedMemory;
}

namespace color_utils {
    struct HSL;
}

namespace gfx {
    class ImageSkia;
}

namespace ui {
    
    typedef uint32_t SkColor;
    
    enum ScaleFactor : int {
        SCALE_FACTOR_NONE = 0,
        SCALE_FACTOR_100P,
        SCALE_FACTOR_125P,
        SCALE_FACTOR_133P,
        SCALE_FACTOR_140P,
        SCALE_FACTOR_150P,
        SCALE_FACTOR_180P,
        SCALE_FACTOR_200P,
        SCALE_FACTOR_250P,
        SCALE_FACTOR_300P,
        
        NUM_SCALE_FACTORS  // This always appears last.
    };
    
    ////////////////////////////////////////////////////////////////////////////////
    //
    // ThemeProvider
    //
    //   ThemeProvider is an abstract class that defines the API that should be
    //   implemented to provide bitmaps and color information for a given theme.
    //
    ////////////////////////////////////////////////////////////////////////////////
    
    class ThemeProvider {
    public:
        virtual ~ThemeProvider();
        
        // Get the image specified by |id|. An implementation of ThemeProvider should
        // have its own source of ids (e.g. an enum, or external resource bundle).
        virtual gfx::ImageSkia* GetImageSkiaNamed(int id) const = 0;
        
        // Get the color specified by |id|.
        virtual SkColor GetColor(int id) const = 0;
        
        // Get the HSL shift specified by |id|.
        virtual color_utils::HSL GetTint(int id) const = 0;
        
        // Get the property (e.g. an alignment expressed in an enum, or a width or
        // height) specified by |id|.
        virtual int GetDisplayProperty(int id) const = 0;
        
        // Whether we should use the native system frame (typically Aero glass) or
        // a custom frame.
        virtual bool ShouldUseNativeFrame() const = 0;
        
        // Whether or not we have a certain image. Used for when the default theme
        // doesn't provide a certain image, but custom themes might (badges, etc).
        virtual bool HasCustomImage(int id) const = 0;
        
        // Reads the image data from the theme file into the specified vector. Only
        // valid for un-themed resources and the themed IDR_THEME_NTP_* in most
        // implementations of ThemeProvider. Returns NULL on error.
        virtual base::RefCountedMemory* GetRawData(
                                                   int id,
                                                   ui::ScaleFactor scale_factor) const = 0;
        
        // Whether we're using the system theme (which may or may not be the
        // same as the default theme).
        // TODO(estade): this should probably just be part of ThemeService and not
        // ThemeProvider, but it's used in many places on OSX.
        virtual bool UsingSystemTheme() const = 0;
        
        // Returns whether or not theme is in Incognito mode.
        virtual bool InIncognitoMode() const = 0;
        
        // Gets the NSImage with the specified |id|.
        virtual NSImage* GetNSImageNamed(int id) const = 0;
        
        // Returns true if the theme has defined a custom color for color |id|.
        virtual bool HasCustomColor(int id) const = 0;
        
        // Gets the NSImage that GetNSImageNamed (above) would return, but returns it
        // as a pattern color.
        virtual NSColor* GetNSImageColorNamed(int id) const = 0;
        
        // Gets the NSColor with the specified |id|.
        virtual NSColor* GetNSColor(int id) const = 0;
        
        // Gets the NSColor for tinting with the specified |id|.
        virtual NSColor* GetNSColorTint(int id) const = 0;
        
        // Gets the NSGradient with the specified |id|.
        virtual NSGradient* GetNSGradient(int id) const = 0;
        
        // Whether the "increase contrast" accessibility setting is enabled.
        virtual bool ShouldIncreaseContrast() const = 0;
    };
    
}  // namespace ui

#endif

