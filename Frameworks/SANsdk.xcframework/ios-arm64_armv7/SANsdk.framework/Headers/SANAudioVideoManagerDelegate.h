//
//  SANAudioVideoManagerDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SANAudioVideoManager;

/// A set of methods to inform the delegate of audio video manager events.
@protocol SANAudioVideoManagerDelegate <NSObject>

@optional

/// Tells the delegate that the SAN Mobile Ads SDK will start playing a video. This method isn't
/// called if another video rendered by SAN Mobile Ads SDK is already playing.
- (void)audioVideoManagerWillPlayVideo:(nonnull SANAudioVideoManager *)audioVideoManager;

/// Tells the delegate that the SAN Mobile Ads SDK has paused/stopped all video playback.
- (void)audioVideoManagerDidPauseAllVideo:(nonnull SANAudioVideoManager *)audioVideoManager;

/// Tells the delegate that at least one video rendered by the SAN Mobile Ads SDK will play
/// sound. Your app should stop playing sound when this method is called.
- (void)audioVideoManagerWillPlayAudio:(nonnull SANAudioVideoManager *)audioVideoManager;

/// Tells the delegate that all the video rendered by the SAN Mobile Ads SDK has stopped playing
/// sound. Your app can now resume any music playback or produce any kind of sound. Note that this
/// message doesn't mean that all the video has stopped playing, just audio, so you shouldn't
/// deactivate AVAudioSession's instance. Doing so can lead to unexpected video playback behavior.
/// You may deactivate AVAudioSession only when all rendered video ads are paused or have finished
/// playing, and 'audioVideoDidPauseAllVideo:' is called.
- (void)audioVideoManagerDidStopPlayingAudio:(nonnull SANAudioVideoManager *)audioVideoManager;

@end
