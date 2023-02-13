//
//  SANMediaContent.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANVideoController.h"

/// Provides media content information. Interact with instances of this class on the main queue
/// only.
@interface SANMediaContent : NSObject

/// Controls the media content's video.
@property(nonatomic, readonly, nonnull) SANVideoController *videoController;

/// Indicates whether the media content has video content.
@property(nonatomic, readonly) BOOL hasVideoContent;

/// Media content aspect ratio (width/height). The value is 0 when there's no media content or the
/// media content aspect ratio is unknown.
@property(nonatomic, readonly) CGFloat aspectRatio;

/// The video's duration in seconds or 0 if there's no video or the duration is unknown.
@property(nonatomic, readonly) NSTimeInterval duration;

/// The video's current playback time in seconds or 0 if there's no video or the current playback
/// time is unknown.
@property(nonatomic, readonly) NSTimeInterval currentTime;

@end

@interface SANMediaContent (NativeAd)

/// The main image to be displayed when the media content doesn't contain video. Only available to
/// native ads.
@property(nonatomic, nullable) UIImage *mainImage;

@end
