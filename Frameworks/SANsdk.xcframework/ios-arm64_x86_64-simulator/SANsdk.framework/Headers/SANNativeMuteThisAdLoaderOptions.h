//
//  SANNativeMuteThisAdLoaderOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"

/// Mute This Ad options.
@interface SANNativeMuteThisAdLoaderOptions : SANAdLoaderOptions

/// Set to YES to request the custom Mute This Ad feature. By default, this property's value is YES.
@property(nonatomic) BOOL customMuteThisAdRequested;

@end
