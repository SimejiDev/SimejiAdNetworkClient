//
//  SANNativeAdImage+Mediation.h
//  SAN SDK
//
//  Copyright 2021 SAN. All rights reserved.
//

#import "SANNativeAdImage.h"

typedef void (^SANAdImageCompletionHandler)(UIImage *_Nullable image);

/// Provides additional SANNativeAdImage initializers.
@interface SANNativeAdImage (MediationAdditions)

/// Initializes and returns a native ad image object with the provided image.
- (nonnull instancetype)initWithImage:(nonnull UIImage *)image;

/// Initializes and returns a native ad image object with the provided image URL and image scale.
- (nonnull instancetype)initWithURL:(nonnull NSURL *)URL scale:(CGFloat)scale completion:(_Nullable SANAdImageCompletionHandler)completion;

@end
