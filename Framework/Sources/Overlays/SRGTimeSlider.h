//
//  Copyright (c) SRG SSR. All rights reserved.
//
//  License information is available from the LICENSE file.
//

#import "SRGMediaPlayerController.h"

#import <CoreMedia/CoreMedia.h>
#import <UIKit/UIKit.h>

// Forward declarations
@protocol SRGTimeSliderDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 *  The slider knob position when a live stream is played (the knob itself cannot be moved). The default value is left,
 *  as for the standard iOS playback controller.
 */
typedef NS_ENUM(NSInteger, SRGTimeSliderLiveKnobPosition) {
    SRGTimeSliderLiveKnobPositionDefault = 0,
    SRGTimeSliderLiveKnobPositionLeft = SRGTimeSliderLiveKnobPositionDefault,
    SRGTimeSliderLiveKnobPositionRight
};

/**
 *  A slider displaying the playback position of the associated media player controller (with optional time and remaining
 *  time labels) and providing a way to seek to any position. The slider also display which part of the media has already
 *  been buffered.
 *
 *  Simply install an instance somewhere onto your custom player interface and bind to a media player controller. You
 *  can also bind two labels for displaying the time and the remaining time.
 *
 *  Slider colors can be customized as follows:
 *    - `borderColor`: Color of the small border around the non-elapsed time track (defaults to black) and of the
 *                     preloading progress bar.
 *    - `minimumTrackTintColor`: Elapsed time track color (defaults to white).
 *    - `maximumTrackTintColor`: Remaining time track color (defaults to black).
 *    - `thumbTintColor`: Thumb color (defaults to white).
 */
IB_DESIGNABLE
@interface SRGTimeSlider : UISlider

/**
 *  The playback controller attached to the slider.
 */
@property (nonatomic, weak, nullable) IBOutlet SRGMediaPlayerController *mediaPlayerController;

/**
 *  The delegate receiving slider events.
 */
@property (nonatomic, weak, nullable) IBOutlet id<SRGTimeSliderDelegate> delegate;

/**
 *  Outlet which must be bound to the label displaying the remaining time.
 */
@property (nonatomic, weak, nullable) IBOutlet UILabel *timeLeftValueLabel;

/**
 *  The remaining time string displayed in the corresponding label.
 */
@property (nonatomic, readonly, copy, nullable) NSString *timeLeftValueString;

/**
 *  Outlet which must be bound to the label displaying the current time.
 */
@property (nonatomic, weak, nullable) IBOutlet UILabel *valueLabel;

/**
 *  The current time string displayed in the corresponding label.
 */
@property (nonatomic, readonly, copy, nullable) NSString *valueString;

/**
 *  Bar border color (defaults to black).
 */
@property (nonatomic, null_resettable) IBInspectable UIColor *borderColor;

/**
 *  Buffering bar color (defaults to dark gray).
 */
@property (nonatomic, null_resettable) IBInspectable UIColor *bufferingTrackColor;

/**
 *  The time corresponding to the current slider position.
 *
 *  @discussion While dragging, this property may not reflect the value current time property of the asset being played.
 *              The slider `time` property namely reflects the current slider knob position, not the actual player
 *              position.
 */
@property (nonatomic, readonly) CMTime time;

/**
 *  For DVR and live streams, returns the date corresponding to the current slider position. If the date cannot be
 *  determined or for on-demand streams, the method returns `nil`.
 */
@property (nonatomic, readonly, nullable) NSDate *date;

/**
 *  Return `YES` iff the current slider position matches the conditions of a live feed.
 *
 *  @discussion While dragging, this property may not reflect the value returned by the media player controller `live` 
 *              property. The slider `live` property namely reflects the current slider knob position, not the actual 
 *              player position.
 */
@property (nonatomic, readonly, getter=isLive) BOOL live;

/**
 *  Set to `YES` to have the player seek when the slider knob is moved, or to `NO` if seeking must be performed only
 *  after the knob has been released.
 *
 *  Defaults to `YES`.
 */
@property (nonatomic, getter=isSeekingDuringTracking) IBInspectable BOOL seekingDuringTracking;

/**
 *  Set to `YES` to have the player automatically resume after a seek (if paused).
 *
 *  Defaults to `NO`.
 */
@property (nonatomic, getter=isResumingAfterSeek) IBInspectable BOOL resumingAfterSeek;

/**
 *  The position of the slider knob when playing a livestream. Defaults to `SRGTimeSliderLiveKnobPositionDefault`.
 */
@property (nonatomic) SRGTimeSliderLiveKnobPosition knobLivePosition;

@end

/**
 *  Delegate protocol.
 */
@protocol SRGTimeSliderDelegate <NSObject>

/**
 *  Called when the slider is moved, either interactively or as the result of normal playback.
 *
 *  @param slider      The slider for which the event is received.
 *  @param time        The time at which the slider was moved.
 *  @param value       The corresponding slider value.
 *  @param interactive Whether the change is a result of a user interfaction (`YES`) or not.
 */
- (void)timeSlider:(SRGTimeSlider *)slider isMovingToPlaybackTime:(CMTime)time withValue:(CGFloat)value interactive:(BOOL)interactive;

@end

NS_ASSUME_NONNULL_END
