//
//  RTCVideoView+Private.h
//  RCTWebRTC
//
//  Created by brajendra  kumar on 17/05/21.
//

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


@interface RTCVideoView ()

@property (nonatomic) BOOL mirror1;
@property (nonatomic, weak) WebRTCModule *module;
- (void)setStreamURL:(NSString *)streamURL bridge: (RCTBridge *) bridge;
@property (nonatomic) RTCVideoViewObjectFit objectFit1;

#if !TARGET_OS_OSX
@property (nonatomic, readonly) __kindof UIView<RTCVideoRenderer> *videoView;
#else
@property (nonatomic, readonly) __kindof NSView<RTCVideoRenderer> *videoView;
#endif

@property (nonatomic, strong) RTCVideoTrack *videoTrack;

@end
