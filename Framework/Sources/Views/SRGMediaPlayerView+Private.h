//
//  Copyright (c) SRG SSR. All rights reserved.
//
//  License information is available from the LICENSE file.
//

#import "SRGMediaPlayerView.h"

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Private interface for internal use.
 */
@interface SRGMediaPlayerView (Private)

/**
 *  The motion manager which has been set, if any.
 */
+ (nullable CMMotionManager *)motionManager;

/**
 *  The player associated with the view.
 */
@property (nonatomic, nullable) AVPlayer *player;

/**
 *  The player layer associated with the view.
 */
@property (nonatomic, readonly, nullable) AVPlayerLayer *playerLayer;

@end

NS_ASSUME_NONNULL_END
