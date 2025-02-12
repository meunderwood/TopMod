/*
*
* ***** BEGIN GPL LICENSE BLOCK *****
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software  Foundation,
* Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* The Original Code is Copyright (C) 2005 by xxxxxxxxxxxxxx
* All rights reserved.
*
* The Original Code is: all of this file.
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*
* Short description of this file
*
* name of .hh file containing function prototypes
*
*/

#include <QtGui>

#include "ExtrusionsMode.hh"

/*!
	\ingroup gui
	@{
	
	\class ExtrusionsMode
	\brief Extrusion Operations GUI elements.
	
	\note 
	
	\see ExtrusionsMode
*/

/*!
* \brief Constructor
* 
* @param parent the MainWindow widget
* @param sm the shortcut manager class for adding a custom shortcut to each menu action or icon
* @param actionList the master list of actions for use with the CommandCompleter class
* 
*/
ExtrusionsMode::ExtrusionsMode(QWidget *parent, QShortcutManager *sm, QWidget *actionList)
		: QWidget(parent)
{		
	setParent(0);
	mParent = parent;
	
	//create the stacked widget and all child widget pages
	mDooSabinExtrudeWidget = new QWidget;
  mCubicalExtrudeWidget = new QWidget;
  mDodecahedralExtrudeWidget = new QWidget;
  mIcosahedralExtrudeWidget = new QWidget;
  mOctahedralExtrudeWidget = new QWidget;
  mStellateExtrudeWidget = new QWidget;
  mDoubleStellateExtrudeWidget = new QWidget;
  mDomeExtrudeWidget = new QWidget;
	
	//setup stacked widget pages here, 
	//each in a separate function to make the code more readable
	setupCubicalExtrude();
	setupDooSabinExtrude();
	setupDodecahedralExtrude();
	setupIcosahedralExtrude();
	setupOctahedralExtrude();
	setupStellateExtrude();
	setupDoubleStellateExtrude();
	setupDomeExtrude();
 	
	mDooSabinExtrudeAction = new QAction(QIcon(":images/extrude_doosabin.png"),tr("Doo Sabin"),this);
	mDooSabinExtrudeAction->setCheckable(true);
	sm->registerAction(mDooSabinExtrudeAction, "Extrusion Operations", "");
	mDooSabinExtrudeAction->setStatusTip(tr("Enter Doo Sabin Extrude Mode"));
	mDooSabinExtrudeAction->setToolTip(tr("Doo Sabin Extrude Mode"));
	connect(mDooSabinExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerDooSabinExtrude()));
	actionList->addAction(mDooSabinExtrudeAction);
	
	mCubicalExtrudeAction = new QAction(QIcon(":images/extrude_cubical.png"),tr("Cubical"),this);
	mCubicalExtrudeAction->setCheckable(true);
	sm->registerAction(mCubicalExtrudeAction, "Extrusion Operations", "");
	mCubicalExtrudeAction->setStatusTip(tr("Enter Cubical Extrude Mode"));
	mCubicalExtrudeAction->setToolTip(tr("Cubical Extrude Mode"));
	connect(mCubicalExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerCubicalExtrude()));
	actionList->addAction(mCubicalExtrudeAction);
	
	mDodecahedralExtrudeAction = new QAction(QIcon(":images/extrude_dodecahedral.png"),tr("Dodecahedral"),this);
	mDodecahedralExtrudeAction->setCheckable(true);
	mDodecahedralExtrudeAction->setEnabled(true);
	sm->registerAction(mDodecahedralExtrudeAction, "Extrusion Operations", "");
	mDodecahedralExtrudeAction->setStatusTip(tr("Enter Dodecahedral Extrude Mode"));
	mDodecahedralExtrudeAction->setToolTip(tr("Dodecahedral Extrude Mode"));
	connect(mDodecahedralExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerDodecahedralExtrude()));
	actionList->addAction(mDodecahedralExtrudeAction);
	
	mIcosahedralExtrudeAction = new QAction(QIcon(":images/extrude_icosahedral.png"),tr("Icosahedral"),this);
	mIcosahedralExtrudeAction->setCheckable(true);
	mIcosahedralExtrudeAction->setEnabled(true);
	sm->registerAction(mIcosahedralExtrudeAction, "Extrusion Operations", "");
	mIcosahedralExtrudeAction->setStatusTip(tr("Enter Icosahedral Extrude Mode"));
	mIcosahedralExtrudeAction->setToolTip(tr("Icosahedral Extrude Mode"));
	connect(mIcosahedralExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerIcosahedralExtrude()));
	actionList->addAction(mIcosahedralExtrudeAction);
	
	mOctahedralExtrudeAction = new QAction(QIcon(":images/extrude_octahedral.png"),tr("Octahedral"),this);
	mOctahedralExtrudeAction->setCheckable(true);
	mOctahedralExtrudeAction->setEnabled(true);
	sm->registerAction(mOctahedralExtrudeAction, "Extrusion Operations", "");
	mOctahedralExtrudeAction->setStatusTip(tr("Enter Octahedral Extrude Mode"));
	mOctahedralExtrudeAction->setToolTip(tr("Octahedral Extrude Mode"));
	connect(mOctahedralExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerOctahedralExtrude()));
	actionList->addAction(mOctahedralExtrudeAction);
	
	mStellateExtrudeAction = new QAction(QIcon(":images/extrude_stellate.png"),tr("Stellate"),this);
	mStellateExtrudeAction->setCheckable(true);
	sm->registerAction(mStellateExtrudeAction, "Extrusion Operations", "");
	mStellateExtrudeAction->setStatusTip(tr("Enter Stellate Extrude Mode"));
	mStellateExtrudeAction->setToolTip(tr("Stellate Extrude Mode"));
	connect(mStellateExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerStellateExtrude()));
	actionList->addAction(mStellateExtrudeAction);
	
	mDoubleStellateExtrudeAction = new QAction(QIcon(":images/extrude_doublestellate.png"),tr("Double Stellate"),this);
	mDoubleStellateExtrudeAction->setCheckable(true);
	sm->registerAction(mDoubleStellateExtrudeAction, "Extrusion Operations", "");
	mDoubleStellateExtrudeAction->setStatusTip(tr("Enter Double Stellate Mode"));
	mDoubleStellateExtrudeAction->setToolTip(tr("Double Stellate Mode"));
	connect(mDoubleStellateExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerDoubleStellateExtrude()));
	actionList->addAction(mDoubleStellateExtrudeAction);

	mDomeExtrudeAction = new QAction(QIcon(":images/extrude_dome.png"),tr("Dome"),this);
	mDomeExtrudeAction->setCheckable(true);
	sm->registerAction(mDomeExtrudeAction, "Extrusion Operations", "");
	mDomeExtrudeAction->setStatusTip(tr("Enter Dome Extrude Mode"));
	mDomeExtrudeAction->setToolTip(tr("Dome Extrude Mode"));
	connect(mDomeExtrudeAction, SIGNAL(triggered()), this, SLOT(triggerDomeExtrude()));
	actionList->addAction(mDomeExtrudeAction);
}

QMenu* ExtrusionsMode::getMenu(){
	
	mExtrusionMenu = new QMenu(tr("Extrusion"));
	
	mExtrusionMenu->addAction(mDooSabinExtrudeAction);
	mExtrusionMenu->addAction(mCubicalExtrudeAction);
	mExtrusionMenu->addAction(mDodecahedralExtrudeAction);
	mExtrusionMenu->addAction(mIcosahedralExtrudeAction);
	mExtrusionMenu->addAction(mOctahedralExtrudeAction);
	mExtrusionMenu->addAction(mStellateExtrudeAction);
	mExtrusionMenu->addAction(mDoubleStellateExtrudeAction);	
	mExtrusionMenu->addAction(mDomeExtrudeAction);	
	
	return mExtrusionMenu;	
}

void ExtrusionsMode::addActions(QActionGroup *actionGroup, QToolBar *toolBar, QStackedWidget *stackedWidget){
	
	actionGroup->addAction(mDooSabinExtrudeAction);
	actionGroup->addAction(mCubicalExtrudeAction);
	actionGroup->addAction(mDodecahedralExtrudeAction);
	actionGroup->addAction(mIcosahedralExtrudeAction);
	actionGroup->addAction(mOctahedralExtrudeAction);
	actionGroup->addAction(mStellateExtrudeAction);
	actionGroup->addAction(mDoubleStellateExtrudeAction);
	actionGroup->addAction(mDomeExtrudeAction);
	
	toolBar->addAction(mDooSabinExtrudeAction);
	toolBar->addAction(mCubicalExtrudeAction);
	toolBar->addAction(mDodecahedralExtrudeAction);   
	toolBar->addAction(mIcosahedralExtrudeAction);   	
	toolBar->addAction(mOctahedralExtrudeAction);     
	toolBar->addAction(mStellateExtrudeAction);
	toolBar->addAction(mDoubleStellateExtrudeAction);
	toolBar->addAction(mDomeExtrudeAction);
	
	stackedWidget->addWidget(mDooSabinExtrudeWidget);
	stackedWidget->addWidget(mCubicalExtrudeWidget);
	stackedWidget->addWidget(mDodecahedralExtrudeWidget);   
	stackedWidget->addWidget(mIcosahedralExtrudeWidget);   	
	stackedWidget->addWidget(mOctahedralExtrudeWidget);     
	stackedWidget->addWidget(mStellateExtrudeWidget);
	stackedWidget->addWidget(mDoubleStellateExtrudeWidget);
	stackedWidget->addWidget(mDomeExtrudeWidget);
	
}

void ExtrusionsMode::triggerDooSabinExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mDooSabinExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeFaceDS);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::DooSabinExtrude);
	((MainWindow*)mParent)->setSpinBoxes(dooSabinLengthSpinBox,dooSabinTwistSpinBox,dooSabinScaleSpinBox,dooSabinSegmentsSpinBox);
}

void ExtrusionsMode::triggerCubicalExtrude(){

	((MainWindow*)mParent)->setToolOptions(mCubicalExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeFace);	
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::CubicalExtrude);
	((MainWindow*)mParent)->setSpinBoxes(cubicalLengthSpinBox,cubicalRotationSpinBox,cubicalScaleSpinBox,cubicalSegmentsSpinBox);
}

void ExtrusionsMode::triggerDodecahedralExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mDodecahedralExtrudeWidget);
	// if (((MainWindow*)mParent)->getExtrudeMultiple())
	// 	((MainWindow*)mParent)->setMode(MainWindow::SelectMultiple);
	// else
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeFaceDodeca);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::DodecahedralExtrude);
	((MainWindow*)mParent)->setSpinBoxes(dodecahedralLengthSpinBox,dodecahedralScaleSpinBox,dodecahedralSegmentsSpinBox);
}

void ExtrusionsMode::triggerIcosahedralExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mIcosahedralExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeFaceIcosa);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::IcosahedralExtrude);
	((MainWindow*)mParent)->setSpinBoxes(icosahedralLengthSpinBox,icosahedralScaleSpinBox,icosahedralSegmentsSpinBox);
}

void ExtrusionsMode::triggerOctahedralExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mOctahedralExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeDualFace);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::OctahedralExtrude);
	((MainWindow*)mParent)->setSpinBoxes(octahedralLengthSpinBox,octahedralRotationSpinBox,octahedralScaleSpinBox,octahedralSegmentsSpinBox);
}

void ExtrusionsMode::triggerStellateExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mStellateExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::StellateFace);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::StellateExtrude);
	((MainWindow*)mParent)->setSpinBoxes(stellateLengthSpinBox);
}

void ExtrusionsMode::triggerDoubleStellateExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mDoubleStellateExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::DoubleStellateFace);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::DoubleStellateExtrude);
	((MainWindow*)mParent)->setSpinBoxes(doubleStellateLengthSpinBox);
}

void ExtrusionsMode::triggerDomeExtrude(){
	
	((MainWindow*)mParent)->setToolOptions(mDomeExtrudeWidget);
	((MainWindow*)mParent)->setMode(MainWindow::ExtrudeFaceDome);
	((MainWindow*)mParent)->setExtrusionMode(MainWindow::DomeExtrude);
	((MainWindow*)mParent)->setSpinBoxes(domeHeightSpinBox,domeRotationSpinBox,domeScaleSpinBox);
}

void ExtrusionsMode::setLength(double value){
	dooSabinLengthSpinBox->setValue(value);
	cubicalLengthSpinBox->setValue(value);
	// dodecahedralLengthSpinBox->setValue(value);
	// icosahedralLengthSpinBox->setValue(value);
	octahedralLengthSpinBox->setValue(value);
	stellateLengthSpinBox->setValue(value);
	doubleStellateLengthSpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength(value);
}
void ExtrusionsMode::setRotation(double value){
	dooSabinTwistSpinBox->setValue(value);
	cubicalRotationSpinBox->setValue(value);
	octahedralRotationSpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeRotation((int)value);
}

void ExtrusionsMode::setSegments(double value){
	dooSabinSegmentsSpinBox->setValue(value);
	cubicalSegmentsSpinBox->setValue(value);
	dodecahedralSegmentsSpinBox->setValue(value);
	icosahedralSegmentsSpinBox->setValue(value);
	octahedralSegmentsSpinBox->setValue(value);

	((MainWindow*)mParent)->changeNumExtrusions((int)value);
}

void ExtrusionsMode::setScale(double value){
	dooSabinScaleSpinBox->setValue(value);
	cubicalScaleSpinBox->setValue(value);
	// dodecahedralScaleSpinBox->setValue(value);
	// icosahedralScaleSpinBox->setValue(value);
	octahedralScaleSpinBox->setValue(value);
		
	((MainWindow*)mParent)->changeExtrudeScale(value);
}

void ExtrusionsMode::setLength1(double value){
	// dodecahedralLength1SpinBox->setValue(value);
	// icosahedralLength1SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength1(value);
}

void ExtrusionsMode::setLength2(double value){
	// dodecahedralLength2SpinBox->setValue(value);
	// icosahedralLength2SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength2(value);
}

void ExtrusionsMode::setLength3(double value){
	// dodecahedralLength3SpinBox->setValue(value);
	// icosahedralLength3SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength3(value);
}

void ExtrusionsMode::setAngle(double value){
	// dodecahedralAngleSpinBox->setValue(value);
	// icosahedralAngleSpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeAngle(value);
}

void ExtrusionsMode::setLength1Icosa(double value){
	// dodecahedralLength1SpinBox->setValue(value);
	// icosahedralLength1SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength1Icosa(value);
}

void ExtrusionsMode::setLength2Icosa(double value){
	// dodecahedralLength2SpinBox->setValue(value);
	// icosahedralLength2SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength2Icosa(value);
}

void ExtrusionsMode::setLength3Icosa(double value){
	// dodecahedralLength3SpinBox->setValue(value);
	// icosahedralLength3SpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeLength3Icosa(value);
}

void ExtrusionsMode::setAngleIcosa(double value){
	// dodecahedralAngleSpinBox->setValue(value);
	// icosahedralAngleSpinBox->setValue(value);
	
	((MainWindow*)mParent)->changeExtrudeAngleIcosa(value);
}

void ExtrusionsMode::toggleCubicalTriangulateFace(int state){
	((MainWindow*)mParent)->toggleTriangulateNewFaces(state);
  if ((bool)state) {
    cubicalScherkCollinsCheckBox->setChecked(Qt::Unchecked);
  }
}

void ExtrusionsMode::toggleCubicalScherkCollins(int state) {
	((MainWindow*)mParent)->toggleScherkCollins(state);
  if ((bool)state) {
    cubicalTriangulateNewFacesCheckBox->setChecked(Qt::Unchecked);
    cubicalPinchSpinBox->setEnabled(true);
    cubicalPinchCenterSpinBox->setEnabled(true);
    cubicalPinchWidthSpinBox->setEnabled(true);
  } else {
    cubicalPinchSpinBox->setEnabled(false);
    cubicalPinchCenterSpinBox->setEnabled(false);
    cubicalPinchWidthSpinBox->setEnabled(false);
  }
}

void ExtrusionsMode::ChangeScherkCollinsPinch(double value) {
	((MainWindow*)mParent)->changeScherkCollinsPinch(value);
}

void ExtrusionsMode::ChangeScherkCollinsPinchCenter(double value) {
	((MainWindow*)mParent)->changeScherkCollinsPinchCenter(value);
}

void ExtrusionsMode::ChangeScherkCollinsPinchWidth(double value) {
	((MainWindow*)mParent)->changeScherkCollinsPinchWidth(value);
}



QDoubleSpinBox *ExtrusionsMode::createDoubleSpinBox(QGridLayout *layout, QLabel *label, QString s, double low, double high, double step, double value, double decimals, int row, int col){
	// label = new QLabel(s,this);
	label->setText(s);
	QDoubleSpinBox *spinbox = new QDoubleSpinBox(this);
	spinbox->setAccelerated(true);
	spinbox->setRange(low, high);
	spinbox->setSingleStep(step);
	spinbox->setValue(value);
	spinbox->setDecimals(decimals);
	spinbox->setMaximumSize(75,25);
	layout->addWidget(label,row,col);
  layout->addWidget(spinbox,row,col+1);

	return spinbox;
}

void ExtrusionsMode::setupDooSabinExtrude(){
	
	mDooSabinExtrudeLayout = new QGridLayout;
	mDooSabinExtrudeLayout->setVerticalSpacing(1);
	mDooSabinExtrudeLayout->setHorizontalSpacing(1);
	// mDooSabinExtrudeLayout->setMargin(0);
	//length
	dooSabinLengthLabel = new QLabel(this);
	dooSabinLengthSpinBox = createDoubleSpinBox(mDooSabinExtrudeLayout, dooSabinLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 3, 0,0);
	connect(dooSabinLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	//rotation
	dooSabinTwistLabel = new QLabel(this);
	dooSabinTwistSpinBox = createDoubleSpinBox(mDooSabinExtrudeLayout, dooSabinTwistLabel, tr("Twist"), -5, 5, .01, 0.0, 3, 1,0);
	connect(dooSabinTwistSpinBox, SIGNAL(valueChanged(double)),((MainWindow*)mParent), SLOT(changeDooSabinExtrudeTwist(double)));
	//scale
	dooSabinScaleLabel = new QLabel(this);
	dooSabinScaleSpinBox = createDoubleSpinBox(mDooSabinExtrudeLayout, dooSabinScaleLabel, tr("Scale"), 0.0, 10.0, 0.01, 1.0, 3, 2,0);
	connect(dooSabinScaleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setScale(double)));
	//segments
	dooSabinSegmentsLabel = new QLabel(this);
	dooSabinSegmentsSpinBox = createDoubleSpinBox(mDooSabinExtrudeLayout, dooSabinSegmentsLabel, tr("Segments"), 1, 50, 1, 1, 0, 3,0);
	connect(dooSabinSegmentsSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setSegments(double)));

	performDooSabinExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performDooSabinExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mDooSabinExtrudeLayout->addWidget(performDooSabinExtrusionButton,4,0,1,2);	

	mDooSabinExtrudeLayout->setRowStretch(5,1);
	mDooSabinExtrudeLayout->setColumnStretch(2,1);
	mDooSabinExtrudeWidget->setWindowTitle(tr("Doo Sabin Extrusion"));
	mDooSabinExtrudeWidget->setLayout(mDooSabinExtrudeLayout);	
}

void ExtrusionsMode::setupCubicalExtrude(){	
	mCubicalExtrudeLayout = new QGridLayout;
	mCubicalExtrudeLayout->setVerticalSpacing(1);
	mCubicalExtrudeLayout->setHorizontalSpacing(1);
	// mCubicalExtrudeLayout->setMargin(0);
	//length
	cubicalLengthLabel = new QLabel(this);
	cubicalLengthSpinBox = createDoubleSpinBox(mCubicalExtrudeLayout, cubicalLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 3, 0,0);
	connect(cubicalLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	//rotation
	cubicalRotationLabel = new QLabel(this);
	cubicalRotationSpinBox = createDoubleSpinBox(mCubicalExtrudeLayout, cubicalRotationLabel, tr("Rotation"), 0, 360, 1, 0.0, 3, 1,0);
	connect(cubicalRotationSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setRotation(double)));
	//scale
	cubicalScaleLabel = new QLabel(this);
	cubicalScaleSpinBox = createDoubleSpinBox(mCubicalExtrudeLayout, cubicalScaleLabel, tr("Scale"), 0.0, 10.0, 0.01, 1.0, 3, 2,0);
	connect(cubicalScaleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setScale(double)));
	//segments
	cubicalSegmentsLabel = new QLabel(this);
	cubicalSegmentsSpinBox = createDoubleSpinBox(mCubicalExtrudeLayout, cubicalSegmentsLabel, tr("Segments"), 1, 50, 1, 1, 0, 3,0);
	connect(cubicalSegmentsSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setSegments(double)));

	performCubicalExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performCubicalExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mCubicalExtrudeLayout->addWidget(performCubicalExtrusionButton,4,0,1,2);	

	cubicalTriangulateNewFacesCheckBox = new QCheckBox(tr("Triangulate New Faces"), this);	
	connect(cubicalTriangulateNewFacesCheckBox, SIGNAL(stateChanged(int)), this,
          SLOT(toggleCubicalTriangulateFace(int)));
	mCubicalExtrudeLayout->addWidget(cubicalTriangulateNewFacesCheckBox, 5, 0, 1, 2);

	cubicalScherkCollinsCheckBox = new QCheckBox(tr("Scherk Collins"), this);	
	connect(cubicalScherkCollinsCheckBox, SIGNAL(stateChanged(int)), this,
          SLOT(toggleCubicalScherkCollins(int)));
	mCubicalExtrudeLayout->addWidget(cubicalScherkCollinsCheckBox, 6, 0, 1, 2);

	QLabel *cubicalPinchLabel = new QLabel(this);
	cubicalPinchSpinBox = createDoubleSpinBox(
      mCubicalExtrudeLayout, cubicalPinchLabel,
      tr("Pinch"), -1, 10, 0.1, 1.0, 2, 7, 0);	
	connect(cubicalPinchSpinBox, SIGNAL(valueChanged(double)),
          this, SLOT(ChangeScherkCollinsPinch(double)));

	QLabel *cubicalPinchCenterLabel = new QLabel(this);
	cubicalPinchCenterSpinBox = createDoubleSpinBox(
      mCubicalExtrudeLayout, cubicalPinchCenterLabel,
      tr("Pinch Center"), 0.1, 1, 0.1, 0.5, 3, 8, 0);	
	connect(cubicalPinchCenterSpinBox, SIGNAL(valueChanged(double)),
          this, SLOT(ChangeScherkCollinsPinchCenter(double)));

	QLabel *cubicalPinchWidthLabel = new QLabel(this);
	cubicalPinchWidthSpinBox = createDoubleSpinBox(
      mCubicalExtrudeLayout, cubicalPinchWidthLabel,
      tr("Pinch Width"), 0.001, 10, 0.1, 1.0, 3, 9, 0);	
	connect(cubicalPinchWidthSpinBox, SIGNAL(valueChanged(double)),
          this, SLOT(ChangeScherkCollinsPinchWidth(double)));

	mCubicalExtrudeLayout->setRowStretch(9,1);
	mCubicalExtrudeLayout->setColumnStretch(2,1);
	mCubicalExtrudeWidget->setWindowTitle(tr("Cubical Extrusion"));
	mCubicalExtrudeWidget->setLayout(mCubicalExtrudeLayout);	
}

void ExtrusionsMode::setupDodecahedralExtrude(){
	mDodecahedralExtrudeLayout = new QGridLayout;
	mDodecahedralExtrudeLayout->setVerticalSpacing(1);
	mDodecahedralExtrudeLayout->setHorizontalSpacing(1);
	// mDodecahedralExtrudeLayout->setMargin(0);
	// //length
	// dodecahedralLengthSpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 1, 0,0);
	// connect(dodecahedralLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	//length1
	dodecahedralLength1Label = new QLabel(this);
	dodecahedralLength1SpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralLength1Label, tr("Length 1"), 0.0, 100.0, 0.1, 0.5, 3, 0,0);
	connect(dodecahedralLength1SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength1(double)));
	//length2
	dodecahedralLength2Label = new QLabel(this);
	dodecahedralLength2SpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralLength2Label, tr("Length 2"), 0.0, 100.0, 0.1, 1.0, 3, 1,0);
	connect(dodecahedralLength2SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength2(double)));
	//length3
	dodecahedralLength3Label = new QLabel(this);
	dodecahedralLength3SpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralLength3Label, tr("Length 3"), 0.0, 100.0, 0.1, 1.0, 3, 2,0);
	connect(dodecahedralLength3SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength3(double)));
	//angle
	dodecahedralAngleLabel = new QLabel(this);
	dodecahedralAngleSpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralAngleLabel, tr("Angle"), 0.0, 180.0, 0.1, 40.0, 3, 3,0);
	connect(dodecahedralAngleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setAngle(double)));
	// //scale
	// dodecahedralScaleSpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralScaleLabel, tr("Scale"), 0.0, 10.0, 0.01, 1.0, 2, 1,0);
	// connect(dodecahedralScaleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setScale(double)));
	//segments
	dodecahedralSegmentsLabel = new QLabel(this);
	dodecahedralSegmentsSpinBox = createDoubleSpinBox(mDodecahedralExtrudeLayout, dodecahedralSegmentsLabel, tr("Segments"), 1, 50, 1, 1, 0, 4,0);
	connect(dodecahedralSegmentsSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setSegments(double)));	
	//mesh flat edges checkbox
	hexagonalizeCheckBox = new QCheckBox(tr("Hexagonalize"),this);
	connect(hexagonalizeCheckBox, SIGNAL(stateChanged(int)),((MainWindow*)mParent), SLOT(toggleHexagonalizeDodecaExtrudeFlag(int)));
	
	mDodecahedralExtrudeLayout->addWidget(hexagonalizeCheckBox,5,1);

	performDodecahedralExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performDodecahedralExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mDodecahedralExtrudeLayout->addWidget(performDodecahedralExtrusionButton,6,0,1,2);	

	mDodecahedralExtrudeLayout->setRowStretch(7,1);
	mDodecahedralExtrudeLayout->setColumnStretch(2,1);
	mDodecahedralExtrudeWidget->setWindowTitle(tr("Dodecahedral Extrusion"));
	mDodecahedralExtrudeWidget->setLayout(mDodecahedralExtrudeLayout);	
}

void ExtrusionsMode::setupIcosahedralExtrude(){
	mIcosahedralExtrudeLayout = new QGridLayout;
	mIcosahedralExtrudeLayout->setVerticalSpacing(1);
	mIcosahedralExtrudeLayout->setHorizontalSpacing(1);
	// mIcosahedralExtrudeLayout->setMargin(0);
	//length
	// icosahedralLengthSpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 1, 0,0);
	// connect(icosahedralLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	//scale
	// icosahedralScaleSpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralScaleLabel, tr("Scale"), 0.0, 10.0, 0.01, 1.0, 2, 1,0);
	// connect(icosahedralScaleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setScale(double)));

	//length1
	icosahedralLength1Label = new QLabel(this);
	icosahedralLength1SpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralLength1Label, tr("Length 1"), 0.0, 100.0, 0.1, 0.5, 3, 0,0);
	connect(icosahedralLength1SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength1Icosa(double)));
	//length2
	icosahedralLength2Label = new QLabel(this);
	icosahedralLength2SpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralLength2Label, tr("Length 2"), 0.0, 100.0, 0.1, 0.7, 3, 1,0);
	connect(icosahedralLength2SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength2Icosa(double)));
	//length3
	icosahedralLength3Label = new QLabel(this);
	icosahedralLength3SpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralLength3Label, tr("Length 3"), 0.0, 100.0, 0.1, 0.8, 3, 2,0);
	connect(icosahedralLength3SpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength3Icosa(double)));
	//angle
	icosahedralAngleLabel = new QLabel(this);
	icosahedralAngleSpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralAngleLabel, tr("Angle"), 0.0, 180.0, 0.1, 50.0, 3, 3,0);
	connect(icosahedralAngleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setAngleIcosa(double)));
	//segments
	icosahedralSegmentsLabel = new QLabel(this);
	icosahedralSegmentsSpinBox = createDoubleSpinBox(mIcosahedralExtrudeLayout, icosahedralSegmentsLabel, tr("Segments"), 1, 50, 1, 1, 0, 4,0);
	connect(icosahedralSegmentsSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setSegments(double)));	

	performIcosahedralExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performIcosahedralExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mIcosahedralExtrudeLayout->addWidget(performIcosahedralExtrusionButton,5,0,1,2);	

	mIcosahedralExtrudeLayout->setRowStretch(6,1);
	mIcosahedralExtrudeLayout->setColumnStretch(2,1);
	mIcosahedralExtrudeWidget->setWindowTitle(tr("Icosahedral Extrusion"));
	mIcosahedralExtrudeWidget->setLayout(mIcosahedralExtrudeLayout);
}

void ExtrusionsMode::setupOctahedralExtrude(){
	mOctahedralExtrudeLayout = new QGridLayout;
	mOctahedralExtrudeLayout->setVerticalSpacing(1);
	mOctahedralExtrudeLayout->setHorizontalSpacing(1);
	// mOctahedralExtrudeLayout->setMargin(0);
	//length
	octahedralLengthLabel = new QLabel(this);
	octahedralLengthSpinBox = createDoubleSpinBox(mOctahedralExtrudeLayout, octahedralLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 3, 0,0);
	connect(octahedralLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	//rotation
	octahedralRotationLabel = new QLabel(this);
	octahedralRotationSpinBox = createDoubleSpinBox(mOctahedralExtrudeLayout, octahedralRotationLabel, tr("Rotation"), 0, 360, 1, 0.0, 3, 1,0);
	connect(octahedralRotationSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setRotation(double)));
	//scale
	octahedralScaleLabel = new QLabel(this);
	octahedralScaleSpinBox = createDoubleSpinBox(mOctahedralExtrudeLayout, octahedralScaleLabel, tr("Scale"), 0.0, 10.0, 0.01, 1.0, 3, 2,0);
	connect(octahedralScaleSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setScale(double)));
	//segments
	octahedralSegmentsLabel = new QLabel(this);
	octahedralSegmentsSpinBox = createDoubleSpinBox(mOctahedralExtrudeLayout, octahedralSegmentsLabel, tr("Segments"), 1, 50, 1, 1, 0, 3,0);
	connect(octahedralSegmentsSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setSegments(double)));
	//mesh flat edges checkbox
	meshFlatEdgesCheckBox = new QCheckBox(tr("Mesh Flat Edges"),this);
	connect(meshFlatEdgesCheckBox, SIGNAL(stateChanged(int)), ((MainWindow*)mParent), SLOT(toggleDualMeshEdgesFlag(int)));

	mOctahedralExtrudeLayout->addWidget(meshFlatEdgesCheckBox,4,1);
	
	performOctahedralExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performOctahedralExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mOctahedralExtrudeLayout->addWidget(performOctahedralExtrusionButton,5,0,1,2);	
	
	mOctahedralExtrudeLayout->setRowStretch(6,1);
	mOctahedralExtrudeLayout->setColumnStretch(2,1);
	mOctahedralExtrudeWidget->setWindowTitle(tr("Octahedral Extrusion"));
	mOctahedralExtrudeWidget->setLayout(mOctahedralExtrudeLayout);
}

void ExtrusionsMode::setupStellateExtrude(){
	mStellateExtrudeLayout = new QGridLayout;
	mStellateExtrudeLayout->setVerticalSpacing(1);
	mStellateExtrudeLayout->setHorizontalSpacing(1);
	// mStellateExtrudeLayout->setMargin(0);
	//length
	stellateLengthLabel = new QLabel(this);
	stellateLengthSpinBox = createDoubleSpinBox(mStellateExtrudeLayout, stellateLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 3, 0,0);
	connect(stellateLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	
	performStellateExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performStellateExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mStellateExtrudeLayout->addWidget(performStellateExtrusionButton,1,0,1,2);	
	
	mStellateExtrudeLayout->setRowStretch(2,1);
	mStellateExtrudeLayout->setColumnStretch(2,1);
	mStellateExtrudeWidget->setWindowTitle(tr("Stellate Extrusion"));
	mStellateExtrudeWidget->setLayout(mStellateExtrudeLayout);	
}

void ExtrusionsMode::setupDoubleStellateExtrude(){
	mDoubleStellateExtrudeLayout = new QGridLayout;
	mDoubleStellateExtrudeLayout->setVerticalSpacing(1);
	mDoubleStellateExtrudeLayout->setHorizontalSpacing(1);
	// mDoubleStellateExtrudeLayout->setMargin(0);
	//length
	doubleStellateLengthLabel = new QLabel(this);
	doubleStellateLengthSpinBox = createDoubleSpinBox(mDoubleStellateExtrudeLayout, doubleStellateLengthLabel, tr("Length"), -100.0, 100.0, 0.1, 2.0, 3, 0,0);
	connect(doubleStellateLengthSpinBox, SIGNAL(valueChanged(double)),this, SLOT(setLength(double)));
	
	performDoubleStellateExtrusionButton = new QPushButton(tr("Extrude Selected Faces"), this);
	connect(performDoubleStellateExtrusionButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mDoubleStellateExtrudeLayout->addWidget(performDoubleStellateExtrusionButton,1,0,1,2);	
	
	mDoubleStellateExtrudeLayout->setRowStretch(2,1);
	mDoubleStellateExtrudeLayout->setColumnStretch(2,1);
	mDoubleStellateExtrudeWidget->setWindowTitle(tr("Double Stellate Extrusion"));
	mDoubleStellateExtrudeWidget->setLayout(mDoubleStellateExtrudeLayout);	
}

void ExtrusionsMode::setupDomeExtrude(){
	mDomeExtrudeLayout = new QGridLayout;
	mDomeExtrudeLayout->setVerticalSpacing(1);
	mDomeExtrudeLayout->setHorizontalSpacing(1);
	// mDomeLayout->setMargin(0);
	domeHeightLabel = new QLabel(this);
	domeHeightSpinBox = createDoubleSpinBox(mDomeExtrudeLayout, domeHeightLabel, tr("Height:"), -10.0, 100.0, 0.01, 1.0, 3, 0,0);
	connect(domeHeightSpinBox, SIGNAL(valueChanged(double)), ((MainWindow*)mParent),SLOT(changeDomeExtrudeLength(double)) );	
	domeRotationLabel = new QLabel(this);
	domeRotationSpinBox = createDoubleSpinBox(mDomeExtrudeLayout, domeRotationLabel, tr("Twist:"), -1.0, 1.0, 0.01, 0.0, 3, 1,0);
	connect(domeRotationSpinBox, SIGNAL(valueChanged(double)), ((MainWindow*)mParent),SLOT(changeDomeExtrudeRotation(double)) );	
	domeScaleLabel = new QLabel(this);
	domeScaleSpinBox = createDoubleSpinBox(mDomeExtrudeLayout, domeScaleLabel, tr("Scale:"), 0.0, 10.0, 0.01, 1.0, 3, 2,0);
	connect(domeScaleSpinBox, SIGNAL(valueChanged(double)), ((MainWindow*)mParent),SLOT(changeDomeExtrudeScale(double)) );	
	domeButton = new QPushButton(tr("Perform Extrusion"), this);
	connect(domeButton, SIGNAL(clicked()), ((MainWindow*)mParent),SLOT(performExtrusion()) );
	mDomeExtrudeLayout->addWidget(domeButton,3,0,1,2);
	mDomeExtrudeLayout->setRowStretch(4,1);
	mDomeExtrudeLayout->setColumnStretch(2,1);
	mDomeExtrudeWidget->setWindowTitle("Dome Extrusion");
	mDomeExtrudeWidget->setLayout(mDomeExtrudeLayout);
}

void ExtrusionsMode::retranslateUi(){
	//actions
	mDooSabinExtrudeAction->setText(tr("Doo Sabin"));
	mDooSabinExtrudeAction->setStatusTip(tr("Enter Doo Sabin Extrude Mode"));
	mDooSabinExtrudeAction->setToolTip(tr("Doo Sabin Extrude Mode"));
	
	mCubicalExtrudeAction->setText(tr("Cubical"));
	mCubicalExtrudeAction->setStatusTip(tr("Enter Cubical Extrude Mode"));
	mCubicalExtrudeAction->setToolTip(tr("Cubical Extrude Mode"));
	
	mDodecahedralExtrudeAction->setText(tr("Dodecahedral"));
	mDodecahedralExtrudeAction->setStatusTip(tr("Enter Dodecahedral Extrude Mode"));
	mDodecahedralExtrudeAction->setToolTip(tr("Dodecahedral Extrude Mode"));
	
	mIcosahedralExtrudeAction->setText(tr("Icosahedral"));
	mIcosahedralExtrudeAction->setStatusTip(tr("Enter Icosahedral Extrude Mode"));
	mIcosahedralExtrudeAction->setToolTip(tr("Icosahedral Extrude Mode"));
	
	mOctahedralExtrudeAction->setText(tr("Octahedral"));
	mOctahedralExtrudeAction->setStatusTip(tr("Enter Octahedral Extrude Mode"));
	mOctahedralExtrudeAction->setToolTip(tr("Octahedral Extrude Mode"));
	
	mStellateExtrudeAction->setText(tr("Stellate"));
	mStellateExtrudeAction->setStatusTip(tr("Enter Stellate Extrude Mode"));
	mStellateExtrudeAction->setToolTip(tr("Stellate Extrude Mode"));
	
	mDoubleStellateExtrudeAction->setText(tr("Double Stellate"));
	mDoubleStellateExtrudeAction->setStatusTip(tr("Enter Double Stellate Mode"));
	mDoubleStellateExtrudeAction->setToolTip(tr("Double Stellate Mode"));

	mDomeExtrudeAction->setText(tr("Dome"));
	mDomeExtrudeAction->setStatusTip(tr("Enter Dome Extrude Mode"));
	mDomeExtrudeAction->setToolTip(tr("Dome Extrude Mode"));
	
	mExtrusionMenu->setTitle(tr("Extrusion"));

	//labels and buttons and stuff
	dooSabinLengthLabel->setText(tr("Length"));
	dooSabinScaleLabel->setText(tr("Scale"));
	dooSabinTwistLabel->setText(tr("Twist"));
	dooSabinSegmentsLabel->setText(tr("Segments"));
	performDooSabinExtrusionButton->setText(tr("Extrude Selected Faces"));
	mDooSabinExtrudeWidget->setWindowTitle(tr("Doo Sabin Extrusion"));
	cubicalLengthLabel->setText(tr("Length"));
	cubicalRotationLabel->setText(tr("Rotation"));
	cubicalScaleLabel->setText(tr("Scale"));
	cubicalSegmentsLabel->setText(tr("Segments"));
	performCubicalExtrusionButton->setText(tr("Extrude Selected Faces"));
	mCubicalExtrudeWidget->setWindowTitle(tr("Cubical Extrusion"));
	dodecahedralLength1Label->setText(tr("Length 1"));
	dodecahedralLength2Label->setText(tr("Length 2"));
	dodecahedralLength3Label->setText(tr("Length 3"));
	dodecahedralAngleLabel->setText(tr("Angle"));
	dodecahedralSegmentsLabel->setText(tr("Segments"));
	hexagonalizeCheckBox->setText(tr("Hexagonalize"));
	performDodecahedralExtrusionButton->setText(tr("Extrude Selected Faces"));
	mDodecahedralExtrudeWidget->setWindowTitle(tr("Dodecahedral Extrusion"));
	icosahedralLength1Label->setText(tr("Length 1"));
	icosahedralLength2Label->setText(tr("Length 2"));
	icosahedralLength3Label->setText(tr("Length 3"));
	icosahedralAngleLabel->setText(tr("Angle"));
	icosahedralSegmentsLabel->setText(tr("Segments"));
	performIcosahedralExtrusionButton->setText(tr("Extrude Selected Faces"));
	mIcosahedralExtrudeWidget->setWindowTitle(tr("Icosahedral Extrusion"));
	octahedralLengthLabel->setText(tr("Length"));
	octahedralRotationLabel->setText(tr("Rotation"));
	octahedralScaleLabel->setText(tr("Scale"));
	octahedralSegmentsLabel->setText(tr("Segments"));
	meshFlatEdgesCheckBox->setText(tr("Mesh Flat Edges"));
	performOctahedralExtrusionButton->setText(tr("Extrude Selected Faces"));
	mOctahedralExtrudeWidget->setWindowTitle(tr("Octahedral Extrusion"));
	stellateLengthLabel->setText(tr("Length"));
	performStellateExtrusionButton->setText(tr("Extrude Selected Faces"));
	mStellateExtrudeWidget->setWindowTitle(tr("Stellate Extrusion"));
	doubleStellateLengthLabel->setText(tr("Length"));
	performDoubleStellateExtrusionButton->setText(tr("Extrude Selected Faces"));
	mDoubleStellateExtrudeWidget->setWindowTitle(tr("Double Stellate Extrusion"));
	domeHeightLabel->setText(tr("Height:"));
	domeRotationLabel->setText(tr("Twist:"));
	domeScaleLabel->setText(tr("Scale:"));
	domeButton->setText(tr("Perform Extrusion"));
	mDomeExtrudeWidget->setWindowTitle("Dome Extrusion");
}
