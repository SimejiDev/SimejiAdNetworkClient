//
//  SANMediaAspectRatio.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Media aspect ratio.
typedef NS_ENUM(NSInteger, SANMediaAspectRatio) {
  /// Unknown media aspect ratio.
  SANMediaAspectRatioUnknown = 0,
  /// Any media aspect ratio.
  SANMediaAspectRatioAny = 1,
  /// Landscape media aspect ratio.
  SANMediaAspectRatioLandscape = 2,
  /// Portrait media aspect ratio.
  SANMediaAspectRatioPortrait = 3,
  /// Close to square media aspect ratio. This is not a strict 1:1 aspect ratio.
  SANMediaAspectRatioSquare = 4
};
