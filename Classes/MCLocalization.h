//
//  MCLocalization.h
//  MCLocalization
//
//  Created by Baglan on 3/14/13.
//  Copyright (c) 2013 MobileCreators. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MCLocalizationDataSource.h"

#define MCLocalizationLanguageDidChangeNotification @"MCLocalizationLanguageDidChangeNotification"

@interface MCLocalization : NSObject

@property (nonatomic, retain) _Nullable id<MCLocalizationDataSource>dataSource;

@property (nonatomic, copy) NSString * _Nonnull language;
@property (nonatomic, readonly) NSArray * _Nonnull supportedLanguages;
@property (nonatomic, readonly) NSString * _Nonnull systemLanguage;

// String using this placeholder will be returned in case a key in not found
// {key} and {language} substring will be substituted for corresponding values
// Default value is nil
@property (nonatomic, copy) NSString * _Nullable noKeyPlaceholder;

+ (NSString * _Nonnull)stringForKey:(NSString * _Nonnull)key;
+ (NSString * _Nonnull)stringForKey:(NSString * _Nonnull)key withPlaceholders:(NSDictionary * _Nonnull)placeholders;
+ (MCLocalization *_Nonnull)sharedInstance;

+ (void)loadFromURL:(NSURL *_Nonnull)JSONFileURL defaultLanguage:(NSString *_Nonnull)defaultLanguage;
+ (void)loadFromLanguageURLPairs:(NSDictionary *_Nonnull)languageURLPairs defaultLanguage:(NSString *_Nonnull)defaultLanguage;

- (void)reloadStrings;

// Methods exposed for extending purposes
- (NSDictionary *_Nonnull)stringsForLanguage:(NSString *_Nonnull)language;
- (NSString *_Nonnull)stringForKey:(NSString *_Nonnull)key language:(NSString *_Nonnull)language;

// Legacy methods
+ (void)loadFromJSONFile:(NSString *_Nonnull)fileName defaultLanguage:(NSString *_Nonnull)defaultLanguage;

@end
