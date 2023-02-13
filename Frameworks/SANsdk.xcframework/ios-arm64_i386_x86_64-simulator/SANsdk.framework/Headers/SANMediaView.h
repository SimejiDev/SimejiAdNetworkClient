//
//  SANMediaView.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANMediaContent.h"

/// Displays native ad media content.
///
/// To display media content in SANNativeAdView instances, add a SANMediaView subview,
/// assign the native ad view's mediaView property, and set the native ad's mediaContent property to
/// the media view.
///
/// If the native ad contains video content, the media view displays the video content.
///
/// If the native ad doesn't have video content and image loading is enabled, the media view
/// displays the first image from the native ad's |images| property.
///
/// If the native ad doesn't have video content and image loading is disabled, the media view is
/// empty.
@interface SANMediaView : UIView

/// The media content displayed in the media view.
@property(nonatomic, nullable) SANMediaContent *mediaContent;

@end
