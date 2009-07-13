#import "Three20/TTTableViewDataSource.h"

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTListDataSource : TTTableViewDataSource {
  NSMutableArray* _items;
}

@property(nonatomic,readonly) NSMutableArray* items;

+ (TTListDataSource*)dataSourceWithObjects:(id)object,...;
+ (TTListDataSource*)dataSourceWithItems:(NSMutableArray*)items;

- (id)initWithItems:(NSArray*)items;

@end

///////////////////////////////////////////////////////////////////////////////////////////////////

@interface TTSectionedDataSource : TTTableViewDataSource {
  NSMutableArray* _sections;
  NSMutableArray* _items;
}

/**
 * Objects should be in this format:
 *
 *   @"section title", item, item, @"section title", item, item, ...
 *
 */
+ (TTSectionedDataSource*)dataSourceWithObjects:(id)object,...;

/**
 * Objects should be in this format:
 *
 *   @"section title", arrayOfItems, @"section title", arrayOfItems, ...
 *
 */
+ (TTSectionedDataSource*)dataSourceWithArrays:(id)object,...;

+ (TTSectionedDataSource*)dataSourceWithItems:(NSArray*)items sections:(NSArray*)sections;

- (id)initWithItems:(NSArray*)items sections:(NSArray*)sections;

- (NSArray*)lettersForSectionsWithSearch:(BOOL)withSearch withCount:(BOOL)withCount;

@end
