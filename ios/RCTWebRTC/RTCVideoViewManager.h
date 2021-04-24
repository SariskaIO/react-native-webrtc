//
//  RTCVideoViewManager.h
//  TestReact
//
//  Created by one on 2015/9/25.
//  Copyright © 2015年 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <React/RCTViewManager.h>
#import "RTCVideoView.h"

@interface RTCVideoViewManager : RCTViewManager
@property (nonatomic, weak) RTCVideoView * v;
- (void)setStreamURL:(NSString *)streamURL;
- (void)setObjectFit:(NSString *)objectFit;
- (void)setMirror:(BOOL)mirror;
@end
