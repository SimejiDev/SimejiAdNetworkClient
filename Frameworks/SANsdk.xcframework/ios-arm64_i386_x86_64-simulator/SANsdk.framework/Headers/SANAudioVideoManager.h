//
//  SANAudioVideoManager.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANAudioVideoManagerDelegate.h"

/// Provides audio and video notifications and configurations management.
///
/// Don't create an instance of this class and use the one available from SANMobileAds
/// sharedInstance's audioVideoManager.
@interface SANAudioVideoManager : NSObject

/// Delegate for receiving video and audio updates.
@property(nonatomic, weak, nullable) id<SANAudioVideoManagerDelegate> delegate;

/// Indicates whether the application wishes to manage audio session. If set as YES, the SAN
/// Mobile Ads SDK will stop managing AVAudioSession during the video playback lifecycle. If set as
/// NO, the SAN Mobile Ads SDK will control AVAudioSession. That may include: setting
/// AVAudioSession's category to AVAudioSessionCategoryAmbient when all videos are muted, setting
/// AVAudioSession's category to AVAudioSessionCategorySoloAmbient when any playing video becomes
/// unmuted, and allowing background apps to continue playing sound when all videos rendered by
/// SAN Mobile Ads SDK are muted or have stopped playing. Must be accessed on main thread only.
@property(nonatomic, assign) BOOL audioSessionIsApplicationManaged;

@end
