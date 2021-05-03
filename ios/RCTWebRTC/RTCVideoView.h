#import <Foundation/Foundation.h>
#import <objc/runtime.h>

#import <React/RCTLog.h>
#if !TARGET_OS_OSX
#import <WebRTC/RTCEAGLVideoView.h>
#endif
#import <WebRTC/RTCMediaStream.h>
#if !TARGET_OS_OSX
#import <WebRTC/RTCMTLVideoView.h>
#else
#import <WebRTC/RTCMTLNSVideoView.h>
#endif
#import <WebRTC/RTCVideoTrack.h>

#import "WebRTCModule.h"
#import "RTCVideoView.h"
#import "Enum.h"
#import <React/RCTBridge.h>


#if !TARGET_OS_OSX
@interface RTCVideoView : UIView <RTCVideoViewDelegate>
#else
@interface RTCVideoView : NSView <RTCVideoViewDelegate>
#endif

/**
 * The indicator which determines whether this {@code RTCVideoView} is to mirror
 * the video specified by {@link #videoTrack} during its rendering. Typically,
 * applications choose to mirror the front/user-facing camera.
 */
@property (nonatomic) BOOL mirror1;

/**
 * In the fashion of
 * https://www.w3.org/TR/html5/embedded-content-0.html#dom-video-videowidth
 * and https://www.w3.org/TR/html5/rendering.html#video-object-fit, resembles
 * the CSS style {@code object-fit}.
 */
@property (nonatomic) RTCVideoViewObjectFit objectFit1;

/**
 * The {@link RRTCVideoRenderer} which implements the actual rendering and which
 * fits within this view so that the rendered video preserves the aspect ratio of
 * {@link #_videoSize}.
 */
#if !TARGET_OS_OSX
@property (nonatomic, readonly) __kindof UIView<RTCVideoRenderer> *videoView;
#else
@property (nonatomic, readonly) __kindof NSView<RTCVideoRenderer> *videoView;
#endif

/**
 * The {@link RTCVideoTrack}, if any, which this instance renders.
 */
@property (nonatomic, strong) RTCVideoTrack *videoTrack;

/**
 * Reference to the main WebRTC RN module.
 */
@property (nonatomic, weak) WebRTCModule *module;

- (void)setStreamURL:(NSString *)streamURL bridge: (RCTBridge *) bridge;
- (void)setObjectFit:(NSString *)objectFit;
- (void)setMirror:(BOOL)mirror;

@end
