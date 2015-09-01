//
//  Copyright (c) RTS. All rights reserved.
//
//  Licence information is available from the LICENCE file.
//

#import "VideosTableViewController.h"

@implementation VideosTableViewController

- (NSString *) mediaURLPath
{
	return @"MediaURLs";
}

- (NSString *) mediaURLKey
{
	return @"Movies";
}

- (NSArray *) actionCellIdentifiers
{
	return @[ @"CellDefaultIOS",
			  @"CellDefaultRTS",
			  @"CellInline"];
}

@end
