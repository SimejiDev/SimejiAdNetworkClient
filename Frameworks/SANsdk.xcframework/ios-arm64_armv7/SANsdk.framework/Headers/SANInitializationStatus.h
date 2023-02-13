//
//  SANInitializationStatus.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SANAdapterInitializationState) {
  /// The mediation adapter is less likely to fill ad requests.
  SANAdapterInitializationStateNotReady = 0,
  /// The mediation adapter is ready to service ad requests.
  SANAdapterInitializationStateReady = 1
};

/// An immutable snapshot of a mediation adapter's initialization status.
@interface SANAdapterStatus : NSObject <NSCopying>

/// Initialization state of the adapter.
@property(nonatomic, readonly) SANAdapterInitializationState state;

/// Detailed description of the status.
@property(nonatomic, readonly, nonnull) NSString *description;

/// The adapter's initialization latency in seconds. 0 if initialization has not yet ended.
@property(nonatomic, readonly) NSTimeInterval latency;

@end

/// An immutable snapshot of the SAN Mobile Ads SDK's initialization status, categorized by
/// mediation adapter.
@interface SANInitializationStatus : NSObject <NSCopying>
/// Initialization status of each ad network available to the SAN Mobile Ads SDK, keyed by its
/// SANMAdapter's class name. The list of available ad networks may be incomplete during early
/// phases of SDK initialization.
@property(nonatomic, readonly, nonnull)
    NSDictionary<NSString *, SANAdapterStatus *> *adapterStatusesByClassName;
@end
