//
//  RTSMediaSegmentsController.h
//  RTSMediaPlayer
//
//  Created by Cédric Foellmi on 27/05/15.
//  Copyright (c) 2015 RTS. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RTSMediaPlayerController;
@protocol RTSMediaPlayerSegment;
@protocol RTSMediaPlayerSegmentDataSource;

@interface RTSMediaSegmentsController : NSObject

@property(nonatomic, weak) IBOutlet RTSMediaPlayerController *playerController;
@property(nonatomic, weak) IBOutlet id<RTSMediaPlayerSegmentDataSource> dataSource;

- (void)reloadDataForIdentifier:(NSString *)identifier onCompletion:(void (^)(void))completionBlock;

/**
 *  The count of segments.
 *
 *  @return An unsigned integer indicating the count of segments.
 */
- (NSUInteger)countOfSegments;

/**
 *  The data sources of each segments.
 *
 *  @return A an array containing the data sources of each segment.
 */
- (NSArray *)segments;

/**
 *  The count of visible segments
 *
 *  @return An unsigned integer indicating the count of episodes.
 */
- (NSUInteger)countOfVisibleSegments;

/**
 *  The data sources of each episodes.
 *
 *  @return A an array containing the data sources of each episodes.
 */
- (NSArray *)visibleSegments;

/**
 *  For each segment index, one must have a given 'visible segment' index.
 *
 *  @param segmentIndex The index of the segment.
 *
 *  @return The index of the episodes corresponding to the provided segment index.
 */
- (NSUInteger)visibleSegmentIndexForSegmentIndex:(NSUInteger)segmentIndex;

/**
 *  Check whether the segment at the given index is blocked.
 *
 *  @param index The index of the segment to be checked.
 *
 *  @return YES if the segment is blocked.
 */
- (BOOL)isSegmentBlockedAtIndex:(NSInteger)index;

/**
 *  When hitting a blocked segment, one must find when exactly restarting the video, if possible. Hence,
 *  given the actual blocked segment at index, we look for the last of the next segments that is also blocked.
 *  Small gaps in between segments (say below < 0.2 seconds) are considered as non-playable content, and
 *  the two segments considered as contiguous.
 *
 *  @param index          The index of the last contiguous segment that is blocked. It can be equal to the current index.
 *  @param flexibilityGap A small gap (say ~ 0.1 sec) used for some flexbility for checking contiguity between segment times.
 *
 *  @return
 *  If there is no more segments and no more playable content, returns NSNotFound;
 */
- (NSInteger)indexOfLastContiguousBlockedSegmentAfterIndex:(NSInteger)index withFlexibilityGap:(CGFloat)flexibilityGap;

@end