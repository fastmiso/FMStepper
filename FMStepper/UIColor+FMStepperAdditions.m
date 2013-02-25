//
//  UIColor+FMStepperAdditions.m
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

#import "UIColor+FMStepperAdditions.h"


@implementation UIColor (FMStepperAdditions)

- (UIColor *)colorDarkenedByFactor:(CGFloat)factor
{
	CGFloat *currentColorComponents = (CGFloat *)CGColorGetComponents([self CGColor]);
	CGFloat newColorComponents[4];

	int nComponents = CGColorGetNumberOfComponents([self CGColor]);

	// Grayscale has 2 color components; RGBA has 4 color components.
	switch (nComponents) {
		case 2: { 
			newColorComponents[0] = currentColorComponents[0] * (1.0f - factor);
			newColorComponents[1] = currentColorComponents[0] * (1.0f - factor);
			newColorComponents[2] = currentColorComponents[0] * (1.0f - factor);
			newColorComponents[3] = currentColorComponents[1];
			break;
		}
		case 4: { // RGBA
			newColorComponents[0] = currentColorComponents[0] * (1.0f - factor);
			newColorComponents[1] = currentColorComponents[1] * (1.0f - factor);
			newColorComponents[2] = currentColorComponents[2] * (1.0f - factor);
			newColorComponents[3] = currentColorComponents[3];
			break;
		}
		default: {
			NSLog(@"Unhandled case in UIColor+FMStepperAdditions: %@", NSStringFromSelector(_cmd));
			return self;
		}
	}

	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	CGColorRef newColor = CGColorCreate(colorSpace, newColorComponents);
	CGColorSpaceRelease(colorSpace);

	UIColor *returnedColor = [UIColor colorWithCGColor:newColor];
	CGColorRelease(newColor);

	return returnedColor;
}

@end
