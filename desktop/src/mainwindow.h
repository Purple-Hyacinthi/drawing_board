#pragma once

#include <QMainWindow>

#include <QVector>

#include "canvaswidget.h"

class QAction;
class QActionGroup;
class QCheckBox;
class QComboBox;
class QDockWidget;
class QDoubleSpinBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QPushButton;
class QSlider;
class QSpinBox;
class QToolBar;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    void initializeWindow();
    void initializeActions();
    void initializeMenus();
    void initializeToolbars();
    void initializeToolDock();
    void initializeLayerDock();
    void initializeStatusBar();
    void connectCanvasSignals();
    void updateWindowState();
    void updateToolDockState();
    void updateLayerDockState();
    void refreshLayerList();

    void chooseBrushColor();
    void chooseTextColor();
    void showNewDocumentDialog();
    void openProject();
    void saveProject();
    void importImage();
    void exportPng();
    void exportSvg();
    void showUsageDialog();
    void showAboutDialog();

    CanvasWidget* canvasWidget_;

    QLabel* documentStatusLabel_;
    QLabel* toolStatusLabel_;
    QLabel* zoomStatusLabel_;

    QDockWidget* toolDock_;
    QLabel* toolSummaryLabel_;
    QPushButton* brushColorButton_;
    QPushButton* textColorButton_;
    QPushButton* eyedropperButton_;
    QVector<QPushButton*> colorPresetButtons_;
    QSpinBox* brushSizeSpinBox_;
    QSpinBox* brushOpacitySpinBox_;
    QCheckBox* pressureCheckBox_;
    QLineEdit* brushNameEdit_;
    QSpinBox* brushAngleSpinBox_;
    QSpinBox* brushRoundnessSpinBox_;
    QSpinBox* brushSpacingSpinBox_;
    QSpinBox* brushHardnessSpinBox_;
    QSpinBox* brushFlowSpinBox_;
    QComboBox* brushSizeModeCombo_;
    QSpinBox* brushJitterSpinBox_;
    QComboBox* eraserModeCombo_;
    QComboBox* shapeTypeCombo_;
    QComboBox* textFontCombo_;
    QSpinBox* textSizeSpinBox_;
    QCheckBox* textBoldCheckBox_;
    QCheckBox* textItalicCheckBox_;
    QComboBox* textAlignCombo_;
    QDoubleSpinBox* textLineHeightSpinBox_;
    QDoubleSpinBox* textLetterSpacingSpinBox_;
    QSlider* filterIntensitySlider_;

    QDockWidget* layerDock_;
    QLineEdit* layerSearchEdit_;
    QListWidget* layerListWidget_;
    QLineEdit* layerNameEdit_;
    QCheckBox* layerVisibleCheckBox_;
    QCheckBox* layerLockedCheckBox_;
    QSlider* layerOpacitySlider_;
    QComboBox* layerBlendModeCombo_;
    QPushButton* addLayerButton_;
    QPushButton* duplicateLayerButton_;
    QPushButton* removeLayerButton_;
    QPushButton* moveLayerUpButton_;
    QPushButton* moveLayerDownButton_;
    QPushButton* mergeDownButton_;
    QPushButton* mergeVisibleButton_;
    QPushButton* clearLayerButton_;

    QAction* newDocumentAction_;
    QAction* openProjectAction_;
    QAction* saveProjectAction_;
    QAction* importImageAction_;
    QAction* exportPngAction_;
    QAction* exportSvgAction_;
    QAction* undoAction_;
    QAction* redoAction_;
    QAction* clearLayerAction_;
    QAction* applySelectionAction_;
    QAction* cancelSelectionAction_;
    QAction* mergeLayerDownAction_;
    QAction* mergeVisibleLayersAction_;
    QAction* zoomInAction_;
    QAction* zoomOutAction_;
    QAction* fitViewAction_;
    QAction* resetViewAction_;
    QAction* grayscaleFilterAction_;
    QAction* sepiaFilterAction_;
    QAction* invertFilterAction_;
    QAction* blurFilterAction_;
    QAction* sharpenFilterAction_;
    QAction* usageAction_;
    QAction* aboutAction_;
    QAction* toggleToolDockAction_;
    QAction* toggleLayerDockAction_;

    QActionGroup* toolActionGroup_;
    QAction* selectToolAction_;
    QAction* brushToolAction_;
    QAction* pencilToolAction_;
    QAction* inkToolAction_;
    QAction* penToolAction_;
    QAction* eraserToolAction_;
    QAction* eyedropperToolAction_;
    QAction* lassoToolAction_;
    QAction* fillToolAction_;
    QAction* shapeToolAction_;
    QAction* textToolAction_;

    bool toolControlsUpdating_;
    bool layerControlsUpdating_;
};
