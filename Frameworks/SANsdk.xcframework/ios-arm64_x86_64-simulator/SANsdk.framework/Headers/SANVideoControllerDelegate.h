//
//  SANVideoControllerDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANVideoController.h"

/// The SANVideoControllerDelegate protocol defines methods that are called by the video controller
/// object in response to the video events that occurred throughout the lifetime of the video
/// rendered by an ad.
@protocol SANVideoControllerDelegate <NSObject>

@optional

/// Tells the delegate that the video controller has began or resumed playing a video.
- (void)videoControllerDidPlayVideo:(nonnull SANVideoController *)videoController;

/// Tells the delegate that the video controller has paused video.
- (void)videoControllerDidPauseVideo:(nonnull SANVideoController *)videoController;

/// Tells the delegate that the video controller's video playback has ended.
- (void)videoControllerDidEndVideoPlayback:(nonnull SANVideoController *)videoController;

/// Tells the delegate that the video controller has muted video.
- (void)videoControllerDidMuteVideo:(nonnull SANVideoController *)videoController;

/// Tells the delegate that the video controller has unmuted video.
- (void)videoControllerDidUnmuteVideo:(nonnull SANVideoController *)videoController;

@end
