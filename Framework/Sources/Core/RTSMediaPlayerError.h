//
//  Copyright (c) SRG. All rights reserved.
//
//  License information is available from the LICENSE file.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Media player error codes
 */
typedef NS_ENUM(NSInteger, RTSMediaPlayerError) {
    /**
     *  Playback error (e.g. playlist could not be read)
     */
    RTSMediaPlayerErrorPlayback,
};

/**
 *  Domain for media player errors
 */
OBJC_EXTERN NSString * const RTSMediaPlayerErrorDomain;

NS_ASSUME_NONNULL_END