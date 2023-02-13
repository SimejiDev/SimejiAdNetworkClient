//
//  SANAdMetadata.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Ad metadata key type.
typedef NSString *SANAdMetadataKey NS_STRING_ENUM;

@protocol SANAdMetadataDelegate;

/// Protocol for ads that provide ad metadata.
@protocol SANAdMetadataProvider <NSObject>

/// The ad's metadata. Use adMetadataDelegate to receive ad metadata change messages.
@property(nonatomic, readonly, nullable) NSDictionary<SANAdMetadataKey, id> *adMetadata;

/// Delegate for receiving ad metadata changes.
@property(nonatomic, weak, nullable) id<SANAdMetadataDelegate> adMetadataDelegate;

@end

/// Delegate protocol for receiving ad metadata change messages from a SANAdMetadataProvider.
@protocol SANAdMetadataDelegate <NSObject>

/// Tells the delegate that the ad's metadata changed. Called when an ad loads and when a loaded
/// ad's metadata changes.
- (void)adMetadataDidChange:(nonnull id<SANAdMetadataProvider>)ad;

@end
