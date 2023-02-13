//
//  SANVideoOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"

/// Video ad options.
@interface SANVideoOptions : SANAdLoaderOptions

/// Indicates whether videos should start muted. By default this property value is YES.
@property(nonatomic, assign) BOOL startMuted;

/// Indicates whether the requested video should have custom controls enabled for
/// play/pause/mute/unmute.
@property(nonatomic, assign) BOOL customControlsRequested;

/// Indicates whether the requested video should have the click to expand behavior.
@property(nonatomic, assign) BOOL clickToExpandRequested;

@end
