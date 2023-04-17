//
//  SANNativeAdViewAdOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"

/// Position of the AdChoices icon in the containing ad.
typedef NS_ENUM(NSInteger, SANAdChoicesPosition) {
  SANAdChoicesPositionTopRightCorner,     ///< Top right corner.
  SANAdChoicesPositionTopLeftCorner,      ///< Top left corner.
  SANAdChoicesPositionBottomRightCorner,  ///< Bottom right corner.
  SANAdChoicesPositionBottomLeftCorner    ///< Bottom Left Corner.
};

/// Ad loader options for configuring the view of native ads.
@interface SANNativeAdViewAdOptions : SANAdLoaderOptions

/// Indicates preferred location of AdChoices icon. Default is SANAdChoicesPositionTopRightCorner.
@property(nonatomic, assign) SANAdChoicesPosition preferredAdChoicesPosition;

@end
