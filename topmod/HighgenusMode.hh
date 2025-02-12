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
*/

/****************************************************************************
 **
 **
 ****************************************************************************/

#ifndef HIGHGENUSMODE_H
#define HIGHGENUSMODE_H

/*!
	\file HighgenusMode.hh
	\brief Definition of the HighgenusMode class
	
	\see HighgenusMode
*/

#include "MainWindow.hh"
class MainWindow;

// Declarition of the class CreateTorusTool.
// We should move it to a file named create_torus_tool.hh later.
// I will create a super class for all the tools. -- Fenghui
class CreateTorusTool: public QWidget {
  Q_OBJECT // does it have to be a Q_OBJECT?

 public:
  QAction *action_;
  QWidget *widget_;
  QGridLayout *layout_;

  CreateTorusTool(QWidget *parent);

 protected:
  QWidget *parent_;

	QDoubleSpinBox *cross_section_radius_spin_;
	QDoubleSpinBox *cross_section_rotation_spin_;
	QDoubleSpinBox *num_partial_twist_spin_;
	QDoubleSpinBox *num_segment_spin_;
	QDoubleSpinBox *num_twist_spin_;
	QDoubleSpinBox *pinch_spin_;
	QDoubleSpinBox *pinch_center_spin_;
	QDoubleSpinBox *pinch_width_spin_;
	QDoubleSpinBox *radius_spin_;
	QCheckBox *triangulate_new_faces_check_;
	QCheckBox *scherk_collins_check_;
	QDoubleSpinBox *size_cross_section_spin_;

	QDoubleSpinBox *hole_num_seg_spin_;
	QDoubleSpinBox *hole_init_skip_spin_;
	QDoubleSpinBox *hole_skip_spin_;
	QDoubleSpinBox *hole_twist_spin_;
	QDoubleSpinBox *hole_seg_skip_spin_;
  QPushButton *apply_button_;

 public slots:
  void Apply();
  void Activate();

  void ToggleTriangulateNewFace(int);
  void ToggleScherkCollins(int);
  void ChangeSizeCrossSection(double);
};
class HighgenusMode : public QWidget {
	Q_OBJECT

public:
	HighgenusMode(QWidget *parent, QShortcutManager *sm, QWidget *actionList);
	void addActions(QActionGroup *actionGroup, QToolBar *toolBar, QStackedWidget *stackedWidget);
	QMenu* getMenu();
	void retranslateUi();
	
	QAction *mAddHoleHandleAction;
	QAction *mAddHoleHandleCVAction;
	QAction *mAddHandleSIAction;
	QAction *mRindModelingScalingAction; 
	QAction *mRindModelingThicknessAction;
	QAction *mWireframeModelingAction; 
	QAction *mWireframeModeling2Action; 
	QAction *mColumnModelingAction;	
	QAction *mSierpinskyAction;
	QAction *mMultiFaceHandleAction;
	QAction *mMengerSpongeAction;
	
	QWidget *mAddHoleHandleWidget;
	QWidget *mAddHoleHandleCVWidget;
	QWidget *mAddHandleSIWidget;
	QWidget *mRindModelingScalingWidget; 
	QWidget *mRindModelingThicknessWidget;
	QWidget *mWireframeModelingWidget; 
	QWidget *mWireframeModeling2Widget; 
	QWidget *mColumnModelingWidget;	
	QWidget *mSierpinskyWidget;
	QWidget *mMultiFaceHandleWidget;
	QWidget *mMengerSpongeWidget;
	
	QGridLayout *mAddHoleHandleLayout;
	QGridLayout *mAddHoleHandleCVLayout;
	QGridLayout *mAddHandleSILayout;
	QGridLayout *mRindModelingScalingLayout;
	QGridLayout *mRindModelingThicknessLayout;
	QGridLayout *mWireframeModelingLayout;
	QGridLayout *mWireframeModeling2Layout;
	QGridLayout *mColumnModelingLayout; 
	QGridLayout *mSierpinskyLayout;
	QGridLayout *mMultiFaceHandleLayout; 
	QGridLayout *mMengerSpongeLayout;
	
    //added by Saied
private:

    QLabel *normalTwistFactor_lable; //Saied
    QSlider *normalTwistFactor_slider; //Saied

public slots:

    void changeNormalTwistingFactor(int factor);//Saied

protected:
	void setupAddHoleHandle();
	void setupAddHoleHandleCV();
	void setupAddHandleSI();
	void setupRindModelingScaling();
	void setupRindModelingThickness();
	void setupWireframeModeling();
	void setupWireframeModeling2();
	void setupColumnModeling();
	void setupSierpinsky();
	void setupMultiFaceHandle();
	void setupMengerSponge();
	
	QDoubleSpinBox *createDoubleSpinBox(QGridLayout *layout, QLabel *label, QString s, double low, double high, double step, double value, double decimals, int row, int col);
	
public slots:
	void numSegmentsValueChanged(double value);
	void changeMultiFaceAlgorithm(bool on);
	void toggleMultiFaceHandleUseMaxOffsetFlag(int state);
	void toggleSymmetricWeightsFlag(int state);
	void toggleWireframeSplit(int state);
	void toggleTriangulateFace(int state);
	void toggleScherkCollins(int state);
	
	void toggleCrustCleanupFlag(int state);
	void numSegmentsConnectValueChanged(double value);
	
	void triggerAddHoleHandle();
	// void triggerCreateTorus();
	void triggerAddHoleHandleCV();
	void triggerAddHandleSI();
	void triggerRindModelingScaling();
	void triggerRindModelingThickness();
	void triggerWireframeModeling();
	void triggerWireframeModeling2();
	void triggerColumnModeling();
	void triggerSierpinsky();
	void triggerMultiFaceHandle();
	void triggerMengerSponge();
	
	void changeHoleHandlePinch(double value);
	void changeHoleHandlePinchCenter(double value);
	void changeHoleHandlePinchWidth(double value);	

	void ChangeScherkCollinsPinch(double value);
	void ChangeScherkCollinsPinchCenter(double value);
	void ChangeScherkCollinsPinchWidth(double value);

	void ChangeScherkCollinsHoleNumSegments(double value);
	void ChangeScherkCollinsHoleInitSkip(double value);
	void ChangeScherkCollinsHoleSkip(double value);
	void ChangeScherkCollinsHoleTwist(double value);
	void ChangeScherkCollinsHoleSegSkip(double value);

private:
	
	QWidget *mParent;
	QMenu *mHighgenusMenu;
  CreateTorusTool *create_torus_tool_;

	QLabel *addHoleHandleNumSegmentsConnectLabel;
	QLabel *addHoleHandleNumSegmentsLabel;
	QLabel *addHoleHandlePinching; //Ryan
	QLabel *addHoleHandlePinchingCenter; //Ryan
    QLabel *addHoleHandlePinchingWidth; //Ryan

    QLabel *addHoleHandleCVNumSegmentsLabel;
	QLabel *addHoleHandleCVNumSegmentsConnectLabel;
	QLabel *addHandleSINumSegmentsLabel;
	QLabel *addHandleSINumSegmentsConnectLabel;
	QLabel *addHandleSIWeight1Label;
	QLabel *addHandleSIWeight2Label;
	QLabel *addHandleSITwistsConnectLabel;
	QLabel *addHandleSIPinchConnectLabel; //Ryan
	QLabel *rindModelingScalingLabel;
	QLabel *rindModelingThicknessLabel;
	QLabel *wireframeModelingThicknessLabel;
	QLabel *wireframeModeling2ThicknessLabel;
	QLabel *wireframeModeling2WidthLabel;
	QLabel *columnModelingThicknessLabel;
	QLabel *mengerSpongeThicknessLabel;
	QLabel *mengerSpongeThresholdLabel;
	QLabel *columnModelingNumSegmentsLabel;
	
	
	QGridLayout *mMultiFaceAlgorithmLayout;
	
	QButtonGroup *multiFaceAlgorithmButtonGroup;
	
	QCheckBox *rindModelingThicknessCleanupCheckBox;
	QCheckBox *rindModelingScalingCleanupCheckBox;
	QCheckBox *AddHandleScherkCollinsCheckBox;

	QCheckBox *triangulateNewFacesCheckBox;
	QCheckBox *addHandleTriangulateNewFacesCheckBox;

	QDoubleSpinBox *addHoleHandleNumSegmentsConnectSpinBox;
	QDoubleSpinBox *addHoleHandleNumSegmentsSpinBox;
	QDoubleSpinBox *addHoleHandlePinchingConnectSpinBox; //Ryan
	QDoubleSpinBox *addHoleHandlePinchingCenterConnectSpinBox; //Ryan
	QDoubleSpinBox *addHoleHandlePinchingWidthConnectSpinBox; //Ryan
	QDoubleSpinBox *addHandleSIBubbleConnectSpinBox; //Ryan
	QDoubleSpinBox *addHandleSIPinchCenterConnectSpinBox; //Ryan
	QCheckBox      *addHandleSIScherkCollinsCheckBox;
	QDoubleSpinBox *addHandleSIPinchSpinBox;
	QDoubleSpinBox *addHandleSIPinchCenterSpinBox;
	QDoubleSpinBox *addHandleSIPinchWidthSpinBox;

	QDoubleSpinBox *addHandleSIHoleNumSegmentsSpinBox;
	QDoubleSpinBox *addHandleSIHoleInitSkipSpinBox;
	QDoubleSpinBox *addHandleSIHoleSkipSpinBox;
	QDoubleSpinBox *addHandleSIHoleTwistSpinBox;
	QDoubleSpinBox *addHandleSIHoleSegSkipSpinBox;

	QDoubleSpinBox *addHoleHandleCVNumSegmentsSpinBox;
	QDoubleSpinBox *addHoleHandleCVNumSegmentsConnectSpinBox;
	
	QDoubleSpinBox *addHandleSINumSegmentsSpinBox;
	QDoubleSpinBox *addHandleSINumSegmentsConnectSpinBox;
	
	QDoubleSpinBox *addHandleSITwistsConnectSpinBox;
	QDoubleSpinBox *addHandleSIWeight1SpinBox;
	QDoubleSpinBox *addHandleSIWeight2SpinBox;
	
	QDoubleSpinBox *addHandleSIPinchConnectSpinBox;//ryan
	QLabel *addHandleSIPinchCenterConnectLabel;//ryan
	QLabel *addHandleSIBubbleConnectLabel;//ryan
	
	
	QDoubleSpinBox *rindModelingScalingSpinBox;
	QDoubleSpinBox *rindModelingThicknessSpinBox;
	QDoubleSpinBox *wireframeModelingThicknessSpinBox;
	QDoubleSpinBox *wireframeModeling2ThicknessSpinBox;
	QDoubleSpinBox *wireframeModeling2WidthSpinBox;
	QDoubleSpinBox *columnModelingThicknessSpinBox;
	QDoubleSpinBox *columnModelingNumSegmentsSpinBox;
	QDoubleSpinBox *mengerSpongeThicknessSpinBox;
	QDoubleSpinBox *mengerSpongeThresholdSpinBox;
		
	QCheckBox *wireframeSplitCheckBox;
	QCheckBox *wireframe2SplitCheckBox;
	
	
	QLabel *multiFaceHandleExtrudeDistanceLabel;
	QLabel *multiFaceHandleScaleLabel;
	QDoubleSpinBox *multiFaceHandleExtrudeDistanceSpinBox;
	QCheckBox *multiFaceHandleMaxOffsetsCheckBox;
	QDoubleSpinBox *multiFaceHandleScaleSpinBox;
	
	QCheckBox *addHandleSISymmetricWeightsCheckBox;
	QPushButton *rindModelingScalingCreateCrustButton;
	QPushButton *rindModelingThicknessCreateButton;
	QPushButton *wireframeModelingCreateButton;
	QPushButton *wireframeModeling2CreateButton;
	QPushButton *columnModelingCreateButton;
	QPushButton *sierpinskyButton;
	QGroupBox *multiFaceAlgorithmGroupBox;
	QPushButton *multiFaceHandleButton;
	QCheckBox *mengerSpongFractionalThicknessCheckBox;
	QPushButton *mengerSpongeButton;
};

#endif
