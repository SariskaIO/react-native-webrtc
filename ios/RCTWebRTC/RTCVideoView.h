#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#if !TARGET_OS_OSX
@interface RTCVideoView : UIView <RTCVideoViewDelegate>
#else
@interface RTCVideoView : NSView <RTCVideoViewDelegate>
#endif
/**
 * Reference to the main WebRTC RN module.
 */
- (void)setObjectFit:(NSString *)objectFit;
- (void)setMirror:(BOOL)mirror;

@end
