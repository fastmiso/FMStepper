Getting Started
------------------
Try out the `FMStepperDemo` project (`FMStepperDemo.xcodeproj`). It contains three examples of differently configured `FMStepper` controls.


Example Usage
-------------
The code to create and configure an `FMStepper` might look something like this:

	// Create
	CGRect frame1 = CGRectMake(xPos, yPos, stepperWidth, stepperHeight);
	FMStepper *stepper = [FMStepper stepperWithFrame:frame1 min:0 max:10 step:1 value:5];
	[stepper addTarget:self action:@selector(stepperChanged:) forControlEvents:UIControlEventValueChanged];
			
	// Customize
	stepper.wraps = YES;
	[stepper setFont:@"Avenir-Book" size:22.0f];
	[stepper setTintColor:[UIColor blueColor]];
	[stepper setCornerRadius:5.0f];
	[stepper setAccessibilityTag:@"columns"];
	
	// Add
	[self.view addSubview:stepper];

For more ways in which you might customize the stepper's appearance, see `FMStepperDemo` or the documentation.


Documentation
-------------
If you have [appledoc](http://gentlebytes.com/appledoc/) installed, you can run the following command from this directory to generate and view an HTML-version of the FMStepper documentation:

	. build_doc.sh

If, for some reason, you would like to install this documentation for use in Xcode, you would run this command from this directory:

	cp -R ./doc/com.fastmiso.FMStepper.docset ~/Library/Developer/Shared/Documentation/DocSets
	
(You might have to restart Xcode to see the docs.) If you don't have [appledoc](http://gentlebytes.com/appledoc/) installed, this may work:

	http://fastmiso.com/docs/FMStepper/


Requirements & Compatibilities
------------------------------
- Tested in the iOS Simulator from iOS 5.1+.
- `FMStepper` uses ARC. If you are using `FMStepper` in a non-ARC project, you must set the `-fobjc-arc` compiler flag on all `FMStepper` source files.


Testing
-------
There is a testing module in the `FMStepperDemo` project to ensure that the value property of the stepper stays sane.


To Do
-----
- Improve predictability of baselines of various fonts in the `UITextField`. (Avenir, e.g., appears to have its baseline too high.) Will probably have to subclass `UITextField` and work in Core Text.
- CocoaPods podspec.


Credits
-------
This control was first inspired by [PAStepper](https://github.com/mperovic/PAStepper)--another UIStepper replacement--and this control incorporates various ideas from that project. The `FMStepper` control differs in at least these respects:

- It is sizable.
- It uses a `UITextField` rather than a `UILabel` to display the current value.
- It accommodates custom fonts and colors without image assets.


Contact
-------
Best is probably [email](hello@fastmiso.com).


License
-------
`FMStepper` is available under the MIT license. See the `LICENSE.txt` file for more information.
