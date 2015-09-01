//
//  Copyright (c) RTS. All rights reserved.
//
//  Licence information is available from the LICENCE file.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

/**
 *  Internal view class for displaying the player
 */
@interface RTSMediaPlayerView : UIView

@property (strong) AVPlayer *player;
@property (readonly) AVPlayerLayer *playerLayer;

@end
