//
//  FMStepperButton.h
//  FMStepper
//
//  Created by Jason Aftosmis on 2/10/13.
//  Copyright (c) 2013 Fast Miso Software, LLC (http://fastmiso.com/)
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import <UIKit/UIKit.h>


/**
 An enumeration for the various styles of stepper buttons.
 */
typedef NS_ENUM(NSInteger, FMStepperButtonStyle) {
    FMStepperButtonStyleLeftMinus,
    FMStepperButtonStyleRightPlus,
    FMStepperButtonStyleCount
};



/**
 An FMStepperButton is a `UIButton` subclass used in the `FMStepper` class.
	Its most salient feature is square corners on on side, with rounded corners
	on the other. The button's color is controlled without the use of image assets.
 
 ## Constants
 
 ### Button Styles

 An enumeration for the various styles of stepper buttons.
 
	typedef NS_ENUM(NSInteger, FMStepperButtonStyle) {
		FMStepperButtonStyleLeft,
		FMStepperButtonStyleRight,
		FMStepperButtonStyleCount
	};
 */
@interface FMStepperButton : UIButton


/**
 The base color of the button. When the button is dimmed or made transparent
	it is from this property that the button's appearance is restored.
	We are thus far avoiding using the tintColor property on UIButton superclass (TODO).
 The default value of this property is `UIColor darkGrayColor`.
 */
@property (strong, nonatomic) UIColor *color;


/**
 The corner radius of two outer corners of the button.
	The default value is 20% of the height of the control.
 */
@property (nonatomic) CGFloat cornerRadius;


/**
 Initializes and returns a newly allocated stepper with the specified frame rectangle.
	@param frame The frame rectangle for the view, measured in points.
	@param style An `FMStepperButtonStyle` value to specify whether this is a
		left (`FMStepperButtonStyleLeft`) or right (`FMStepperButtonStyleRight`) button.
	@return An initialized view object or nil if the object couldn't be created.
 */
- (id)initWithFrame:(CGRect)frame style:(FMStepperButtonStyle)style;


/**
 Set the tag/name to use when describing the variable with VoiceOver via UIAccessibility.
 */
- (void)configureAccessibilityWithTag:(NSString *)tag;

@end
