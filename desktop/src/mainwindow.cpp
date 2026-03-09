#include "mainwindow.h"

#include <QAction>
#include <QActionGroup>
#include <QCheckBox>
#include <QColorDialog>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDockWidget>
#include <QDoubleSpinBox>
#include <QFileDialog>
#include <QFormLayout>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QSignalBlocker>
#include <QSlider>
#include <QSpinBox>
#include <QStatusBar>
#include <QToolBar>
#include <QVBoxLayout>

namespace {

void applyColorButtonStyle(QPushButton* button, const QColor& color, bool circular = false, bool selected = false) {
    if (!button) {
        return;
    }

    const QColor safeColor = color.isValid() ? color : QColor(QStringLiteral("#000000"));
    const QString background = safeColor.name(QColor::HexRgb);
    const QString foreground = safeColor.lightnessF() >= 0.55 ? QStringLiteral("#0f172a") : QStringLiteral("#f8fafc");
    const QString border = selected ? QStringLiteral("2px solid #2563eb") : QStringLiteral("1px solid #94a3b8");
    const QString radius = circular ? QStringLiteral("14px") : QStringLiteral("6px");
    button->setText(circular ? QString() : background.toUpper());
    button->setStyleSheet(QStringLiteral("QPushButton { background:%1; color:%2; border:%3; border-radius:%4; padding:6px 10px; }").arg(background, foreground, border, radius));
}

QString shapeTypeLabel(CanvasWidget::ShapeType shapeType) {
    switch (shapeType) {
    case CanvasWidget::ShapeType::Line: return QStringLiteral("直线");
    case CanvasWidget::ShapeType::Curve: return QStringLiteral("曲线");
    case CanvasWidget::ShapeType::Ellipse: return QStringLiteral("椭圆");
    case CanvasWidget::ShapeType::Rectangle: return QStringLiteral("矩形");
    case CanvasWidget::ShapeType::RoundedRectangle: return QStringLiteral("圆角矩形");
    case CanvasWidget::ShapeType::Triangle: return QStringLiteral("三角形");
    case CanvasWidget::ShapeType::Diamond: return QStringLiteral("菱形");
    case CanvasWidget::ShapeType::Pentagon: return QStringLiteral("五边形");
    case CanvasWidget::ShapeType::Hexagon: return QStringLiteral("六边形");
    case CanvasWidget::ShapeType::RightArrow: return QStringLiteral("右箭头");
    case CanvasWidget::ShapeType::LeftArrow: return QStringLiteral("左箭头");
    case CanvasWidget::ShapeType::UpArrow: return QStringLiteral("上箭头");
    case CanvasWidget::ShapeType::DownArrow: return QStringLiteral("下箭头");
    case CanvasWidget::ShapeType::Star4: return QStringLiteral("四角星");
    case CanvasWidget::ShapeType::Star5: return QStringLiteral("五角星");
    case CanvasWidget::ShapeType::ChatBubble: return QStringLiteral("对话框");
    case CanvasWidget::ShapeType::Heart: return QStringLiteral("爱心");
    }
    return QStringLiteral("直线");
}

QString blendModeLabel(CanvasWidget::LayerBlendMode blendMode) {
    switch (blendMode) {
    case CanvasWidget::LayerBlendMode::SourceOver: return QStringLiteral("正常");
    case CanvasWidget::LayerBlendMode::Multiply: return QStringLiteral("正片叠底");
    case CanvasWidget::LayerBlendMode::Screen: return QStringLiteral("滤色");
    case CanvasWidget::LayerBlendMode::Overlay: return QStringLiteral("叠加");
    case CanvasWidget::LayerBlendMode::Darken: return QStringLiteral("变暗");
    case CanvasWidget::LayerBlendMode::Lighten: return QStringLiteral("变亮");
    }
    return QStringLiteral("正常");
}

QString sizeModeLabel(CanvasWidget::SizeMode sizeMode) {
    switch (sizeMode) {
    case CanvasWidget::SizeMode::Fixed: return QStringLiteral("固定");
    case CanvasWidget::SizeMode::Random: return QStringLiteral("随机");
    case CanvasWidget::SizeMode::Pressure: return QStringLiteral("压力");
    }
    return QStringLiteral("固定");
}

}  // namespace

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      canvasWidget_(new CanvasWidget(this)),
      documentStatusLabel_(nullptr),
      toolStatusLabel_(nullptr),
      zoomStatusLabel_(nullptr),
      toolDock_(nullptr),
      toolSummaryLabel_(nullptr),
      brushColorButton_(nullptr),
      textColorButton_(nullptr),
      eyedropperButton_(nullptr),
      colorPresetButtons_(),
      brushSizeSpinBox_(nullptr),
      brushOpacitySpinBox_(nullptr),
      pressureCheckBox_(nullptr),
      brushNameEdit_(nullptr),
      brushAngleSpinBox_(nullptr),
      brushRoundnessSpinBox_(nullptr),
      brushSpacingSpinBox_(nullptr),
      brushHardnessSpinBox_(nullptr),
      brushFlowSpinBox_(nullptr),
      brushSizeModeCombo_(nullptr),
      brushJitterSpinBox_(nullptr),
      eraserModeCombo_(nullptr),
      shapeTypeCombo_(nullptr),
      textFontCombo_(nullptr),
      textSizeSpinBox_(nullptr),
      textBoldCheckBox_(nullptr),
      textItalicCheckBox_(nullptr),
      textAlignCombo_(nullptr),
      textLineHeightSpinBox_(nullptr),
      textLetterSpacingSpinBox_(nullptr),
      filterIntensitySlider_(nullptr),
      layerDock_(nullptr),
      layerSearchEdit_(nullptr),
      layerListWidget_(nullptr),
      layerNameEdit_(nullptr),
      layerVisibleCheckBox_(nullptr),
      layerLockedCheckBox_(nullptr),
      layerOpacitySlider_(nullptr),
      layerBlendModeCombo_(nullptr),
      addLayerButton_(nullptr),
      duplicateLayerButton_(nullptr),
      removeLayerButton_(nullptr),
      moveLayerUpButton_(nullptr),
      moveLayerDownButton_(nullptr),
      mergeDownButton_(nullptr),
      mergeVisibleButton_(nullptr),
      clearLayerButton_(nullptr),
      newDocumentAction_(nullptr),
      openProjectAction_(nullptr),
      saveProjectAction_(nullptr),
      importImageAction_(nullptr),
      exportPngAction_(nullptr),
      exportSvgAction_(nullptr),
      undoAction_(nullptr),
      redoAction_(nullptr),
      clearLayerAction_(nullptr),
      applySelectionAction_(nullptr),
      cancelSelectionAction_(nullptr),
      mergeLayerDownAction_(nullptr),
      mergeVisibleLayersAction_(nullptr),
      zoomInAction_(nullptr),
      zoomOutAction_(nullptr),
      fitViewAction_(nullptr),
      resetViewAction_(nullptr),
      grayscaleFilterAction_(nullptr),
      sepiaFilterAction_(nullptr),
      invertFilterAction_(nullptr),
      blurFilterAction_(nullptr),
      sharpenFilterAction_(nullptr),
      usageAction_(nullptr),
      aboutAction_(nullptr),
      toggleToolDockAction_(nullptr),
      toggleLayerDockAction_(nullptr),
      toolActionGroup_(nullptr),
      selectToolAction_(nullptr),
      brushToolAction_(nullptr),
      pencilToolAction_(nullptr),
      inkToolAction_(nullptr),
      penToolAction_(nullptr),
      eraserToolAction_(nullptr),
      eyedropperToolAction_(nullptr),
      lassoToolAction_(nullptr),
      fillToolAction_(nullptr),
      shapeToolAction_(nullptr),
      textToolAction_(nullptr),
      toolControlsUpdating_(false),
      layerControlsUpdating_(false) {
    setCentralWidget(canvasWidget_);
    initializeWindow();
}

MainWindow::~MainWindow() = default;

void MainWindow::initializeWindow() {
    resize(1600, 980);
    setWindowTitle(QStringLiteral("Drawing Board Pro Desktop"));
    setDockNestingEnabled(true);

    initializeActions();
    initializeMenus();
    initializeToolbars();
    initializeToolDock();
    initializeLayerDock();
    initializeStatusBar();
    connectCanvasSignals();
    updateWindowState();
}

void MainWindow::initializeActions() {
    newDocumentAction_ = new QAction(QStringLiteral("新建文档"), this);
    newDocumentAction_->setShortcut(QKeySequence::New);
    connect(newDocumentAction_, &QAction::triggered, this, &MainWindow::showNewDocumentDialog);

    openProjectAction_ = new QAction(QStringLiteral("打开文件"), this);
    openProjectAction_->setShortcut(QKeySequence::Open);
    connect(openProjectAction_, &QAction::triggered, this, &MainWindow::openProject);

    saveProjectAction_ = new QAction(QStringLiteral("保存项目"), this);
    saveProjectAction_->setShortcut(QKeySequence::Save);
    connect(saveProjectAction_, &QAction::triggered, this, &MainWindow::saveProject);

    importImageAction_ = new QAction(QStringLiteral("导入图片"), this);
    connect(importImageAction_, &QAction::triggered, this, &MainWindow::importImage);

    exportPngAction_ = new QAction(QStringLiteral("导出 PNG"), this);
    connect(exportPngAction_, &QAction::triggered, this, &MainWindow::exportPng);

    exportSvgAction_ = new QAction(QStringLiteral("导出 SVG"), this);
    connect(exportSvgAction_, &QAction::triggered, this, &MainWindow::exportSvg);

    undoAction_ = new QAction(QStringLiteral("撤销"), this);
    undoAction_->setShortcut(QKeySequence::Undo);
    connect(undoAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::undo);

    redoAction_ = new QAction(QStringLiteral("重做"), this);
    redoAction_->setShortcuts({QKeySequence::Redo, QKeySequence(QStringLiteral("Ctrl+Shift+Z"))});
    connect(redoAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::redo);

    clearLayerAction_ = new QAction(QStringLiteral("清空当前层"), this);
    connect(clearLayerAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::clearActiveLayer);

    applySelectionAction_ = new QAction(QStringLiteral("应用浮动选区"), this);
    connect(applySelectionAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::applyFloatingSelection);

    cancelSelectionAction_ = new QAction(QStringLiteral("取消浮动选区"), this);
    connect(cancelSelectionAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::cancelFloatingSelection);

    mergeLayerDownAction_ = new QAction(QStringLiteral("向下合并当前层"), this);
    connect(mergeLayerDownAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::mergeActiveLayerDown);

    mergeVisibleLayersAction_ = new QAction(QStringLiteral("合并可见图层"), this);
    connect(mergeVisibleLayersAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::mergeVisibleLayers);

    zoomInAction_ = new QAction(QStringLiteral("放大"), this);
    zoomInAction_->setShortcut(QKeySequence::ZoomIn);
    connect(zoomInAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::zoomIn);

    zoomOutAction_ = new QAction(QStringLiteral("缩小"), this);
    zoomOutAction_->setShortcut(QKeySequence::ZoomOut);
    connect(zoomOutAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::zoomOut);

    fitViewAction_ = new QAction(QStringLiteral("适应窗口"), this);
    fitViewAction_->setShortcut(QKeySequence(QStringLiteral("Ctrl+0")));
    connect(fitViewAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::fitToViewport);

    resetViewAction_ = new QAction(QStringLiteral("重置视图"), this);
    resetViewAction_->setShortcut(QKeySequence(QStringLiteral("Ctrl+Shift+0")));
    connect(resetViewAction_, &QAction::triggered, canvasWidget_, &CanvasWidget::resetView);

    grayscaleFilterAction_ = new QAction(QStringLiteral("黑白"), this);
    connect(grayscaleFilterAction_, &QAction::triggered, this, [this]() { canvasWidget_->applyFilter(CanvasWidget::FilterType::Grayscale); });
    sepiaFilterAction_ = new QAction(QStringLiteral("棕褐"), this);
    connect(sepiaFilterAction_, &QAction::triggered, this, [this]() { canvasWidget_->applyFilter(CanvasWidget::FilterType::Sepia); });
    invertFilterAction_ = new QAction(QStringLiteral("反相"), this);
    connect(invertFilterAction_, &QAction::triggered, this, [this]() { canvasWidget_->applyFilter(CanvasWidget::FilterType::Invert); });
    blurFilterAction_ = new QAction(QStringLiteral("模糊"), this);
    connect(blurFilterAction_, &QAction::triggered, this, [this]() { canvasWidget_->applyFilter(CanvasWidget::FilterType::Blur); });
    sharpenFilterAction_ = new QAction(QStringLiteral("锐化"), this);
    connect(sharpenFilterAction_, &QAction::triggered, this, [this]() { canvasWidget_->applyFilter(CanvasWidget::FilterType::Sharpen); });

    usageAction_ = new QAction(QStringLiteral("使用提示"), this);
    usageAction_->setShortcut(QKeySequence(Qt::Key_F1));
    connect(usageAction_, &QAction::triggered, this, &MainWindow::showUsageDialog);

    aboutAction_ = new QAction(QStringLiteral("关于桌面版"), this);
    connect(aboutAction_, &QAction::triggered, this, &MainWindow::showAboutDialog);

    toggleToolDockAction_ = new QAction(QStringLiteral("颜色与属性面板"), this);
    toggleToolDockAction_->setCheckable(true);
    toggleToolDockAction_->setChecked(true);

    toggleLayerDockAction_ = new QAction(QStringLiteral("图层面板"), this);
    toggleLayerDockAction_->setCheckable(true);
    toggleLayerDockAction_->setChecked(true);

    toolActionGroup_ = new QActionGroup(this);
    toolActionGroup_->setExclusive(true);
    auto createToolAction = [this](const QString& text, CanvasWidget::ToolId toolId) {
        QAction* action = new QAction(text, this);
        action->setCheckable(true);
        action->setData(static_cast<int>(toolId));
        toolActionGroup_->addAction(action);
        connect(action, &QAction::triggered, this, [this, toolId]() { canvasWidget_->setActiveTool(toolId); });
        return action;
    };
    selectToolAction_ = createToolAction(QStringLiteral("选择"), CanvasWidget::ToolId::Select);
    brushToolAction_ = createToolAction(QStringLiteral("画笔"), CanvasWidget::ToolId::Brush);
    pencilToolAction_ = createToolAction(QStringLiteral("铅笔"), CanvasWidget::ToolId::Pencil);
    inkToolAction_ = createToolAction(QStringLiteral("毛笔"), CanvasWidget::ToolId::Ink);
    penToolAction_ = createToolAction(QStringLiteral("钢笔"), CanvasWidget::ToolId::Pen);
    eraserToolAction_ = createToolAction(QStringLiteral("橡皮"), CanvasWidget::ToolId::Eraser);
    eyedropperToolAction_ = createToolAction(QStringLiteral("拾色器"), CanvasWidget::ToolId::Eyedropper);
    lassoToolAction_ = createToolAction(QStringLiteral("套索"), CanvasWidget::ToolId::Lasso);
    fillToolAction_ = createToolAction(QStringLiteral("填充"), CanvasWidget::ToolId::Fill);
    shapeToolAction_ = createToolAction(QStringLiteral("形状"), CanvasWidget::ToolId::Shape);
    textToolAction_ = createToolAction(QStringLiteral("文字"), CanvasWidget::ToolId::Text);
    brushToolAction_->setChecked(true);
}

void MainWindow::initializeMenus() {
    auto* fileMenu = menuBar()->addMenu(QStringLiteral("文件"));
    fileMenu->addAction(newDocumentAction_);
    fileMenu->addAction(openProjectAction_);
    fileMenu->addAction(saveProjectAction_);
    fileMenu->addSeparator();
    fileMenu->addAction(importImageAction_);
    fileMenu->addAction(exportPngAction_);
    fileMenu->addAction(exportSvgAction_);

    auto* editMenu = menuBar()->addMenu(QStringLiteral("编辑"));
    editMenu->addAction(undoAction_);
    editMenu->addAction(redoAction_);
    editMenu->addSeparator();
    editMenu->addAction(clearLayerAction_);
    editMenu->addAction(applySelectionAction_);
    editMenu->addAction(cancelSelectionAction_);
    editMenu->addAction(mergeLayerDownAction_);
    editMenu->addAction(mergeVisibleLayersAction_);

    auto* viewMenu = menuBar()->addMenu(QStringLiteral("视图"));
    viewMenu->addAction(zoomInAction_);
    viewMenu->addAction(zoomOutAction_);
    viewMenu->addAction(fitViewAction_);
    viewMenu->addAction(resetViewAction_);
    viewMenu->addSeparator();
    viewMenu->addAction(toggleToolDockAction_);
    viewMenu->addAction(toggleLayerDockAction_);

    auto* filterMenu = menuBar()->addMenu(QStringLiteral("滤镜"));
    filterMenu->addAction(grayscaleFilterAction_);
    filterMenu->addAction(sepiaFilterAction_);
    filterMenu->addAction(invertFilterAction_);
    filterMenu->addAction(blurFilterAction_);
    filterMenu->addAction(sharpenFilterAction_);

    auto* helpMenu = menuBar()->addMenu(QStringLiteral("帮助"));
    helpMenu->addAction(usageAction_);
    helpMenu->addAction(aboutAction_);
}

void MainWindow::initializeToolbars() {
    auto* commandBar = addToolBar(QStringLiteral("命令栏"));
    commandBar->setMovable(false);
    commandBar->addAction(newDocumentAction_);
    commandBar->addAction(openProjectAction_);
    commandBar->addAction(saveProjectAction_);
    commandBar->addSeparator();
    commandBar->addAction(undoAction_);
    commandBar->addAction(redoAction_);
    commandBar->addSeparator();
    commandBar->addAction(zoomOutAction_);
    commandBar->addAction(fitViewAction_);
    commandBar->addAction(zoomInAction_);

    auto* toolBar = new QToolBar(QStringLiteral("工具"), this);
    toolBar->setMovable(false);
    toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->addAction(selectToolAction_);
    toolBar->addAction(brushToolAction_);
    toolBar->addAction(pencilToolAction_);
    toolBar->addAction(inkToolAction_);
    toolBar->addAction(penToolAction_);
    toolBar->addAction(eraserToolAction_);
    toolBar->addAction(eyedropperToolAction_);
    toolBar->addAction(lassoToolAction_);
    toolBar->addAction(fillToolAction_);
    toolBar->addAction(shapeToolAction_);
    toolBar->addAction(textToolAction_);
}

void MainWindow::initializeToolDock() {
    toolDock_ = new QDockWidget(QStringLiteral("颜色与属性"), this);
    toolDock_->setObjectName(QStringLiteral("NativeToolDock"));
    auto* panel = new QWidget(toolDock_);
    auto* layout = new QVBoxLayout(panel);

    toolSummaryLabel_ = new QLabel(QStringLiteral("当前工具：画笔"), panel);
    toolSummaryLabel_->setWordWrap(true);

    brushColorButton_ = new QPushButton(panel);
    brushColorButton_->setMinimumHeight(34);
    textColorButton_ = new QPushButton(panel);
    textColorButton_->setMinimumHeight(34);
    eyedropperButton_ = new QPushButton(QStringLiteral("切换拾色器"), panel);

    auto* colorRow = new QHBoxLayout();
    colorRow->addWidget(brushColorButton_, 1);
    colorRow->addWidget(eyedropperButton_);

    auto* presetGrid = new QGridLayout();
    for (int index = 0; index < 9; ++index) {
        auto* button = new QPushButton(panel);
        button->setFixedSize(28, 28);
        colorPresetButtons_.append(button);
        presetGrid->addWidget(button, index / 3, index % 3);
        connect(button, &QPushButton::clicked, this, [this, button]() {
            if (toolControlsUpdating_) {
                return;
            }
            const QColor color(button->property("color").toString());
            canvasWidget_->setBrushColor(color);
        });
    }

    brushSizeSpinBox_ = new QSpinBox(panel);
    brushSizeSpinBox_->setRange(1, 240);
    brushOpacitySpinBox_ = new QSpinBox(panel);
    brushOpacitySpinBox_->setRange(1, 100);
    pressureCheckBox_ = new QCheckBox(QStringLiteral("启用压感"), panel);
    brushNameEdit_ = new QLineEdit(panel);
    brushAngleSpinBox_ = new QSpinBox(panel);
    brushAngleSpinBox_->setRange(0, 180);
    brushRoundnessSpinBox_ = new QSpinBox(panel);
    brushRoundnessSpinBox_->setRange(10, 100);
    brushSpacingSpinBox_ = new QSpinBox(panel);
    brushSpacingSpinBox_->setRange(1, 80);
    brushHardnessSpinBox_ = new QSpinBox(panel);
    brushHardnessSpinBox_->setRange(1, 100);
    brushFlowSpinBox_ = new QSpinBox(panel);
    brushFlowSpinBox_->setRange(1, 100);
    brushSizeModeCombo_ = new QComboBox(panel);
    brushSizeModeCombo_->addItem(sizeModeLabel(CanvasWidget::SizeMode::Fixed), static_cast<int>(CanvasWidget::SizeMode::Fixed));
    brushSizeModeCombo_->addItem(sizeModeLabel(CanvasWidget::SizeMode::Random), static_cast<int>(CanvasWidget::SizeMode::Random));
    brushSizeModeCombo_->addItem(sizeModeLabel(CanvasWidget::SizeMode::Pressure), static_cast<int>(CanvasWidget::SizeMode::Pressure));
    brushJitterSpinBox_ = new QSpinBox(panel);
    brushJitterSpinBox_->setRange(0, 80);
    eraserModeCombo_ = new QComboBox(panel);
    eraserModeCombo_->addItem(QStringLiteral("普通擦除"), static_cast<int>(CanvasWidget::EraserMode::Normal));
    eraserModeCombo_->addItem(QStringLiteral("笔画擦除"), static_cast<int>(CanvasWidget::EraserMode::Stroke));
    shapeTypeCombo_ = new QComboBox(panel);
    for (int value = static_cast<int>(CanvasWidget::ShapeType::Line); value <= static_cast<int>(CanvasWidget::ShapeType::Heart); ++value) {
        const auto shapeType = static_cast<CanvasWidget::ShapeType>(value);
        shapeTypeCombo_->addItem(shapeTypeLabel(shapeType), value);
    }
    textFontCombo_ = new QComboBox(panel);
    textFontCombo_->addItems({QStringLiteral("MiSans"), QStringLiteral("OPPOSans"), QStringLiteral("Noto Sans SC"), QStringLiteral("Noto Serif SC"), QStringLiteral("Source Han Sans SC"), QStringLiteral("Source Han Serif SC"), QStringLiteral("LXGW WenKai"), QStringLiteral("Alibaba PuHuiTi 3.0"), QStringLiteral("HarmonyOS Sans SC")});
    textSizeSpinBox_ = new QSpinBox(panel);
    textSizeSpinBox_->setRange(8, 240);
    textBoldCheckBox_ = new QCheckBox(QStringLiteral("粗体"), panel);
    textItalicCheckBox_ = new QCheckBox(QStringLiteral("斜体"), panel);
    textAlignCombo_ = new QComboBox(panel);
    textAlignCombo_->addItems({QStringLiteral("左对齐"), QStringLiteral("居中"), QStringLiteral("右对齐")});
    textLineHeightSpinBox_ = new QDoubleSpinBox(panel);
    textLineHeightSpinBox_->setRange(0.8, 3.0);
    textLineHeightSpinBox_->setSingleStep(0.05);
    textLetterSpacingSpinBox_ = new QDoubleSpinBox(panel);
    textLetterSpacingSpinBox_->setRange(-8.0, 40.0);
    textLetterSpacingSpinBox_->setSingleStep(0.5);
    filterIntensitySlider_ = new QSlider(Qt::Horizontal, panel);
    filterIntensitySlider_->setRange(0, 100);

    auto* form = new QFormLayout();
    form->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    form->addRow(QStringLiteral("画笔名称"), brushNameEdit_);
    form->addRow(QStringLiteral("画笔颜色"), colorRow);
    form->addRow(QStringLiteral("预设颜色"), presetGrid);
    form->addRow(QStringLiteral("画笔大小"), brushSizeSpinBox_);
    form->addRow(QStringLiteral("画笔不透明度"), brushOpacitySpinBox_);
    form->addRow(QStringLiteral("压感"), pressureCheckBox_);
    form->addRow(QStringLiteral("角度"), brushAngleSpinBox_);
    form->addRow(QStringLiteral("圆度"), brushRoundnessSpinBox_);
    form->addRow(QStringLiteral("间距"), brushSpacingSpinBox_);
    form->addRow(QStringLiteral("硬度"), brushHardnessSpinBox_);
    form->addRow(QStringLiteral("流量"), brushFlowSpinBox_);
    form->addRow(QStringLiteral("尺寸模式"), brushSizeModeCombo_);
    form->addRow(QStringLiteral("抖动"), brushJitterSpinBox_);
    form->addRow(QStringLiteral("橡皮模式"), eraserModeCombo_);
    form->addRow(QStringLiteral("形状类型"), shapeTypeCombo_);
    form->addRow(QStringLiteral("文字颜色"), textColorButton_);
    form->addRow(QStringLiteral("文字字体"), textFontCombo_);
    form->addRow(QStringLiteral("文字字号"), textSizeSpinBox_);
    form->addRow(QStringLiteral("文字样式"), [panel, this]() {
        auto* row = new QWidget(panel);
        auto* rowLayout = new QHBoxLayout(row);
        rowLayout->setContentsMargins(0, 0, 0, 0);
        rowLayout->addWidget(textBoldCheckBox_);
        rowLayout->addWidget(textItalicCheckBox_);
        rowLayout->addStretch();
        return row;
    }());
    form->addRow(QStringLiteral("文字对齐"), textAlignCombo_);
    form->addRow(QStringLiteral("行距"), textLineHeightSpinBox_);
    form->addRow(QStringLiteral("字距"), textLetterSpacingSpinBox_);
    form->addRow(QStringLiteral("滤镜强度"), filterIntensitySlider_);

    layout->addWidget(toolSummaryLabel_);
    layout->addLayout(form);
    layout->addStretch();

    panel->setLayout(layout);
    toolDock_->setWidget(panel);
    addDockWidget(Qt::RightDockWidgetArea, toolDock_);

    connect(toggleToolDockAction_, &QAction::toggled, toolDock_, &QDockWidget::setVisible);
    connect(toolDock_, &QDockWidget::visibilityChanged, toggleToolDockAction_, &QAction::setChecked);

    connect(brushColorButton_, &QPushButton::clicked, this, &MainWindow::chooseBrushColor);
    connect(textColorButton_, &QPushButton::clicked, this, &MainWindow::chooseTextColor);
    connect(eyedropperButton_, &QPushButton::clicked, this, [this]() { canvasWidget_->setActiveTool(CanvasWidget::ToolId::Eyedropper); });
    connect(brushSizeSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) { if (!toolControlsUpdating_) canvasWidget_->setBrushSize(value); });
    connect(brushOpacitySpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) { if (!toolControlsUpdating_) canvasWidget_->setBrushOpacity(value); });
    connect(pressureCheckBox_, &QCheckBox::toggled, this, [this](bool checked) { if (!toolControlsUpdating_) canvasWidget_->setPressureEnabled(checked); });
    connect(brushNameEdit_, &QLineEdit::editingFinished, this, [this]() { if (!toolControlsUpdating_) canvasWidget_->setBrushName(brushNameEdit_->text()); });

    auto pushBrushStyle = [this]() {
        if (toolControlsUpdating_) {
            return;
        }
        CanvasWidget::BrushStyleState style = canvasWidget_->brushStyle();
        style.angle = brushAngleSpinBox_->value();
        style.roundness = brushRoundnessSpinBox_->value();
        style.spacing = brushSpacingSpinBox_->value();
        style.hardness = brushHardnessSpinBox_->value();
        style.flow = brushFlowSpinBox_->value();
        style.sizeMode = static_cast<CanvasWidget::SizeMode>(brushSizeModeCombo_->currentData().toInt());
        style.sizeJitter = brushJitterSpinBox_->value();
        canvasWidget_->setBrushStyle(style);
    };
    connect(brushAngleSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushRoundnessSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushSpacingSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushHardnessSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushFlowSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushSizeModeCombo_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(brushJitterSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushBrushStyle](int) { pushBrushStyle(); });
    connect(eraserModeCombo_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int) {
        if (!toolControlsUpdating_) {
            canvasWidget_->setEraserMode(static_cast<CanvasWidget::EraserMode>(eraserModeCombo_->currentData().toInt()));
        }
    });
    connect(shapeTypeCombo_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int) {
        if (!toolControlsUpdating_) {
            canvasWidget_->setShapeType(static_cast<CanvasWidget::ShapeType>(shapeTypeCombo_->currentData().toInt()));
        }
    });
    auto pushTextStyle = [this]() {
        if (toolControlsUpdating_) {
            return;
        }
        CanvasWidget::TextStyleState style = canvasWidget_->textStyle();
        style.fontFamily = textFontCombo_->currentText();
        style.size = textSizeSpinBox_->value();
        style.bold = textBoldCheckBox_->isChecked();
        style.italic = textItalicCheckBox_->isChecked();
        style.alignment = textAlignCombo_->currentIndex() == 1 ? Qt::AlignHCenter : (textAlignCombo_->currentIndex() == 2 ? Qt::AlignRight : Qt::AlignLeft);
        style.lineHeight = textLineHeightSpinBox_->value();
        style.letterSpacing = textLetterSpacingSpinBox_->value();
        canvasWidget_->setTextStyle(style);
    };
    connect(textFontCombo_, &QComboBox::currentTextChanged, this, [pushTextStyle](const QString&) { pushTextStyle(); });
    connect(textSizeSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), this, [pushTextStyle](int) { pushTextStyle(); });
    connect(textBoldCheckBox_, &QCheckBox::toggled, this, [pushTextStyle](bool) { pushTextStyle(); });
    connect(textItalicCheckBox_, &QCheckBox::toggled, this, [pushTextStyle](bool) { pushTextStyle(); });
    connect(textAlignCombo_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [pushTextStyle](int) { pushTextStyle(); });
    connect(textLineHeightSpinBox_, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [pushTextStyle](double) { pushTextStyle(); });
    connect(textLetterSpacingSpinBox_, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [pushTextStyle](double) { pushTextStyle(); });
    connect(filterIntensitySlider_, &QSlider::valueChanged, this, [this](int value) { if (!toolControlsUpdating_) canvasWidget_->setFilterIntensity(value); });
}

void MainWindow::initializeLayerDock() {
    layerDock_ = new QDockWidget(QStringLiteral("图层"), this);
    layerDock_->setObjectName(QStringLiteral("NativeLayerDock"));
    auto* panel = new QWidget(layerDock_);
    auto* layout = new QVBoxLayout(panel);

    layerSearchEdit_ = new QLineEdit(panel);
    layerSearchEdit_->setPlaceholderText(QStringLiteral("搜索图层名称"));
    layerListWidget_ = new QListWidget(panel);
    layerNameEdit_ = new QLineEdit(panel);
    layerVisibleCheckBox_ = new QCheckBox(QStringLiteral("可见"), panel);
    layerLockedCheckBox_ = new QCheckBox(QStringLiteral("锁定"), panel);
    layerOpacitySlider_ = new QSlider(Qt::Horizontal, panel);
    layerOpacitySlider_->setRange(0, 100);
    layerBlendModeCombo_ = new QComboBox(panel);
    for (int value = static_cast<int>(CanvasWidget::LayerBlendMode::SourceOver); value <= static_cast<int>(CanvasWidget::LayerBlendMode::Lighten); ++value) {
        const auto blend = static_cast<CanvasWidget::LayerBlendMode>(value);
        layerBlendModeCombo_->addItem(blendModeLabel(blend), value);
    }

    addLayerButton_ = new QPushButton(QStringLiteral("新建"), panel);
    duplicateLayerButton_ = new QPushButton(QStringLiteral("复制"), panel);
    removeLayerButton_ = new QPushButton(QStringLiteral("删除"), panel);
    moveLayerUpButton_ = new QPushButton(QStringLiteral("上移"), panel);
    moveLayerDownButton_ = new QPushButton(QStringLiteral("下移"), panel);
    mergeDownButton_ = new QPushButton(QStringLiteral("向下合并"), panel);
    mergeVisibleButton_ = new QPushButton(QStringLiteral("合并可见"), panel);
    clearLayerButton_ = new QPushButton(QStringLiteral("清空当前层"), panel);

    auto* actionGrid = new QGridLayout();
    actionGrid->addWidget(addLayerButton_, 0, 0);
    actionGrid->addWidget(duplicateLayerButton_, 0, 1);
    actionGrid->addWidget(removeLayerButton_, 0, 2);
    actionGrid->addWidget(moveLayerUpButton_, 1, 0);
    actionGrid->addWidget(moveLayerDownButton_, 1, 1);
    actionGrid->addWidget(clearLayerButton_, 1, 2);
    actionGrid->addWidget(mergeDownButton_, 2, 0, 1, 2);
    actionGrid->addWidget(mergeVisibleButton_, 2, 2);

    auto* flagRow = new QHBoxLayout();
    flagRow->addWidget(layerVisibleCheckBox_);
    flagRow->addWidget(layerLockedCheckBox_);
    flagRow->addStretch();
    auto* flagsWidget = new QWidget(panel);
    flagsWidget->setLayout(flagRow);

    auto* form = new QFormLayout();
    form->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    form->addRow(QStringLiteral("当前图层"), layerNameEdit_);
    form->addRow(QStringLiteral("图层状态"), flagsWidget);
    form->addRow(QStringLiteral("不透明度"), layerOpacitySlider_);
    form->addRow(QStringLiteral("混合模式"), layerBlendModeCombo_);

    layout->addWidget(layerSearchEdit_);
    layout->addWidget(layerListWidget_, 1);
    layout->addLayout(actionGrid);
    layout->addLayout(form);

    panel->setLayout(layout);
    layerDock_->setWidget(panel);
    addDockWidget(Qt::RightDockWidgetArea, layerDock_);
    splitDockWidget(toolDock_, layerDock_, Qt::Vertical);

    connect(toggleLayerDockAction_, &QAction::toggled, layerDock_, &QDockWidget::setVisible);
    connect(layerDock_, &QDockWidget::visibilityChanged, toggleLayerDockAction_, &QAction::setChecked);

    connect(layerSearchEdit_, &QLineEdit::textChanged, this, &MainWindow::refreshLayerList);
    connect(layerListWidget_, &QListWidget::currentItemChanged, this, [this](QListWidgetItem* current, QListWidgetItem*) {
        if (layerControlsUpdating_ || !current) {
            return;
        }
        canvasWidget_->setActiveLayer(current->data(Qt::UserRole).toInt());
    });
    connect(layerNameEdit_, &QLineEdit::editingFinished, this, [this]() {
        if (!layerControlsUpdating_) {
            canvasWidget_->renameLayer(canvasWidget_->activeLayerIndex(), layerNameEdit_->text());
        }
    });
    connect(layerVisibleCheckBox_, &QCheckBox::toggled, this, [this](bool checked) {
        if (!layerControlsUpdating_) {
            canvasWidget_->setLayerVisible(canvasWidget_->activeLayerIndex(), checked);
        }
    });
    connect(layerLockedCheckBox_, &QCheckBox::toggled, this, [this](bool checked) {
        if (!layerControlsUpdating_) {
            canvasWidget_->setLayerLocked(canvasWidget_->activeLayerIndex(), checked);
        }
    });
    connect(layerOpacitySlider_, &QSlider::valueChanged, this, [this](int value) {
        if (layerControlsUpdating_) {
            return;
        }
        canvasWidget_->setLayerOpacity(canvasWidget_->activeLayerIndex(), value / 100.0, !layerOpacitySlider_->isSliderDown());
    });
    connect(layerBlendModeCombo_, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int) {
        if (!layerControlsUpdating_) {
            canvasWidget_->setLayerBlendMode(canvasWidget_->activeLayerIndex(), static_cast<CanvasWidget::LayerBlendMode>(layerBlendModeCombo_->currentData().toInt()));
        }
    });
    connect(addLayerButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::addLayer);
    connect(duplicateLayerButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::duplicateActiveLayer);
    connect(removeLayerButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::removeActiveLayer);
    connect(moveLayerUpButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::moveActiveLayerUp);
    connect(moveLayerDownButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::moveActiveLayerDown);
    connect(mergeDownButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::mergeActiveLayerDown);
    connect(mergeVisibleButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::mergeVisibleLayers);
    connect(clearLayerButton_, &QPushButton::clicked, canvasWidget_, &CanvasWidget::clearActiveLayer);
}

void MainWindow::initializeStatusBar() {
    documentStatusLabel_ = new QLabel(this);
    toolStatusLabel_ = new QLabel(this);
    zoomStatusLabel_ = new QLabel(this);
    statusBar()->addPermanentWidget(documentStatusLabel_);
    statusBar()->addPermanentWidget(toolStatusLabel_);
    statusBar()->addPermanentWidget(zoomStatusLabel_);
}

void MainWindow::connectCanvasSignals() {
    connect(canvasWidget_, &CanvasWidget::documentStateChanged, this, &MainWindow::updateWindowState);
    connect(canvasWidget_, &CanvasWidget::toolStateChanged, this, &MainWindow::updateWindowState);
    connect(canvasWidget_, &CanvasWidget::layerStateChanged, this, &MainWindow::updateWindowState);
    connect(canvasWidget_, &CanvasWidget::historyStateChanged, this, &MainWindow::updateWindowState);
    connect(canvasWidget_, &CanvasWidget::viewStateChanged, this, &MainWindow::updateWindowState);
    connect(canvasWidget_, &CanvasWidget::statusMessageRequested, this, [this](const QString& message, int timeoutMs) {
        statusBar()->showMessage(message, timeoutMs <= 0 ? 2000 : timeoutMs);
    });
}

void MainWindow::updateWindowState() {
    documentStatusLabel_->setText(QStringLiteral("文档 %1 (%2 x %3)").arg(canvasWidget_->documentName()).arg(canvasWidget_->documentSize().width()).arg(canvasWidget_->documentSize().height()));
    toolStatusLabel_->setText(QStringLiteral("工具 %1").arg(canvasWidget_->activeToolLabel()));
    zoomStatusLabel_->setText(QStringLiteral("缩放 %1").arg(canvasWidget_->zoomLabel()));
    setWindowTitle(QStringLiteral("%1 - Drawing Board Pro Desktop").arg(canvasWidget_->documentName()));

    undoAction_->setEnabled(canvasWidget_->canUndo());
    redoAction_->setEnabled(canvasWidget_->canRedo());
    clearLayerAction_->setEnabled(canvasWidget_->hasEditableActiveLayer());
    applySelectionAction_->setEnabled(canvasWidget_->hasFloatingSelection());
    cancelSelectionAction_->setEnabled(canvasWidget_->hasFloatingSelection());
    mergeLayerDownAction_->setEnabled(canvasWidget_->canMergeActiveLayerDown());
    const QVector<CanvasWidget::LayerSummary> layerSummaries = canvasWidget_->layerSummaries();
    int visibleLayerCount = 0;
    for (const CanvasWidget::LayerSummary& summary : layerSummaries) {
        if (summary.visible) {
            ++visibleLayerCount;
        }
    }
    mergeVisibleLayersAction_->setEnabled(visibleLayerCount > 1);

    updateToolDockState();
    updateLayerDockState();
}

void MainWindow::updateToolDockState() {
    toolControlsUpdating_ = true;
    const QSignalBlocker brushSizeBlocker(brushSizeSpinBox_);
    const QSignalBlocker brushOpacityBlocker(brushOpacitySpinBox_);
    const QSignalBlocker pressureBlocker(pressureCheckBox_);
    const QSignalBlocker brushNameBlocker(brushNameEdit_);
    const QSignalBlocker brushAngleBlocker(brushAngleSpinBox_);
    const QSignalBlocker brushRoundnessBlocker(brushRoundnessSpinBox_);
    const QSignalBlocker brushSpacingBlocker(brushSpacingSpinBox_);
    const QSignalBlocker brushHardnessBlocker(brushHardnessSpinBox_);
    const QSignalBlocker brushFlowBlocker(brushFlowSpinBox_);
    const QSignalBlocker brushSizeModeBlocker(brushSizeModeCombo_);
    const QSignalBlocker brushJitterBlocker(brushJitterSpinBox_);
    const QSignalBlocker eraserModeBlocker(eraserModeCombo_);
    const QSignalBlocker shapeTypeBlocker(shapeTypeCombo_);
    const QSignalBlocker textFontBlocker(textFontCombo_);
    const QSignalBlocker textSizeBlocker(textSizeSpinBox_);
    const QSignalBlocker textBoldBlocker(textBoldCheckBox_);
    const QSignalBlocker textItalicBlocker(textItalicCheckBox_);
    const QSignalBlocker textAlignBlocker(textAlignCombo_);
    const QSignalBlocker textLineHeightBlocker(textLineHeightSpinBox_);
    const QSignalBlocker textLetterSpacingBlocker(textLetterSpacingSpinBox_);
    const QSignalBlocker filterBlocker(filterIntensitySlider_);

    toolSummaryLabel_->setText(QStringLiteral("当前工具：%1").arg(canvasWidget_->activeToolLabel()));
    applyColorButtonStyle(brushColorButton_, canvasWidget_->brushColor());
    brushColorButton_->setProperty("color", canvasWidget_->brushColor().name(QColor::HexRgb));
    applyColorButtonStyle(textColorButton_, canvasWidget_->textStyle().color);

    const QVector<QString> presets = canvasWidget_->colorPresets();
    for (int index = 0; index < colorPresetButtons_.size(); ++index) {
        const QColor color(index < presets.size() ? presets.at(index) : QStringLiteral("#000000"));
        colorPresetButtons_[index]->setProperty("color", color.name(QColor::HexRgb));
        applyColorButtonStyle(colorPresetButtons_[index], color, true, color == canvasWidget_->brushColor());
    }

    brushSizeSpinBox_->setValue(canvasWidget_->brushSize());
    brushOpacitySpinBox_->setValue(canvasWidget_->brushOpacity());
    pressureCheckBox_->setChecked(canvasWidget_->pressureEnabled());
    brushNameEdit_->setText(canvasWidget_->brushName());

    const CanvasWidget::BrushStyleState style = canvasWidget_->brushStyle();
    brushAngleSpinBox_->setValue(style.angle);
    brushRoundnessSpinBox_->setValue(style.roundness);
    brushSpacingSpinBox_->setValue(style.spacing);
    brushHardnessSpinBox_->setValue(style.hardness);
    brushFlowSpinBox_->setValue(style.flow);
    brushSizeModeCombo_->setCurrentIndex(brushSizeModeCombo_->findData(static_cast<int>(style.sizeMode)));
    brushJitterSpinBox_->setValue(style.sizeJitter);
    eraserModeCombo_->setCurrentIndex(eraserModeCombo_->findData(static_cast<int>(canvasWidget_->eraserMode())));
    shapeTypeCombo_->setCurrentIndex(shapeTypeCombo_->findData(static_cast<int>(canvasWidget_->shapeType())));

    const CanvasWidget::TextStyleState textStyle = canvasWidget_->textStyle();
    textFontCombo_->setCurrentText(textStyle.fontFamily);
    textSizeSpinBox_->setValue(textStyle.size);
    textBoldCheckBox_->setChecked(textStyle.bold);
    textItalicCheckBox_->setChecked(textStyle.italic);
    textAlignCombo_->setCurrentIndex(textStyle.alignment.testFlag(Qt::AlignHCenter) ? 1 : (textStyle.alignment.testFlag(Qt::AlignRight) ? 2 : 0));
    textLineHeightSpinBox_->setValue(textStyle.lineHeight);
    textLetterSpacingSpinBox_->setValue(textStyle.letterSpacing);
    filterIntensitySlider_->setValue(canvasWidget_->filterIntensity());

    const bool brushControlsVisible = canvasWidget_->activeTool() == CanvasWidget::ToolId::Brush || canvasWidget_->activeTool() == CanvasWidget::ToolId::Pencil || canvasWidget_->activeTool() == CanvasWidget::ToolId::Ink || canvasWidget_->activeTool() == CanvasWidget::ToolId::Pen || canvasWidget_->activeTool() == CanvasWidget::ToolId::Eraser;
    const bool textControlsVisible = canvasWidget_->activeTool() == CanvasWidget::ToolId::Text;
    const bool shapeControlsVisible = canvasWidget_->activeTool() == CanvasWidget::ToolId::Shape;
    brushSizeSpinBox_->setEnabled(brushControlsVisible);
    brushOpacitySpinBox_->setEnabled(brushControlsVisible);
    pressureCheckBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushNameEdit_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushAngleSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushRoundnessSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushSpacingSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushHardnessSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushFlowSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushSizeModeCombo_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser);
    brushJitterSpinBox_->setEnabled(brushControlsVisible && canvasWidget_->activeTool() != CanvasWidget::ToolId::Eraser && style.sizeMode == CanvasWidget::SizeMode::Random);
    eraserModeCombo_->setEnabled(canvasWidget_->activeTool() == CanvasWidget::ToolId::Eraser);
    shapeTypeCombo_->setEnabled(shapeControlsVisible);
    textColorButton_->setEnabled(textControlsVisible);
    textFontCombo_->setEnabled(textControlsVisible);
    textSizeSpinBox_->setEnabled(textControlsVisible);
    textBoldCheckBox_->setEnabled(textControlsVisible);
    textItalicCheckBox_->setEnabled(textControlsVisible);
    textAlignCombo_->setEnabled(textControlsVisible);
    textLineHeightSpinBox_->setEnabled(textControlsVisible);
    textLetterSpacingSpinBox_->setEnabled(textControlsVisible);

    switch (canvasWidget_->activeTool()) {
    case CanvasWidget::ToolId::Select: selectToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Brush: brushToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Pencil: pencilToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Ink: inkToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Pen: penToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Eraser: eraserToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Eyedropper: eyedropperToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Lasso: lassoToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Fill: fillToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Shape: shapeToolAction_->setChecked(true); break;
    case CanvasWidget::ToolId::Text: textToolAction_->setChecked(true); break;
    }

    toolControlsUpdating_ = false;
}

void MainWindow::updateLayerDockState() {
    layerControlsUpdating_ = true;
    const QSignalBlocker nameBlocker(layerNameEdit_);
    const QSignalBlocker visibleBlocker(layerVisibleCheckBox_);
    const QSignalBlocker lockedBlocker(layerLockedCheckBox_);
    const QSignalBlocker opacityBlocker(layerOpacitySlider_);
    const QSignalBlocker blendBlocker(layerBlendModeCombo_);

    refreshLayerList();

    const QVector<CanvasWidget::LayerSummary> layers = canvasWidget_->layerSummaries();
    const int activeIndex = canvasWidget_->activeLayerIndex();
    if (activeIndex >= 0 && activeIndex < layers.size()) {
        const CanvasWidget::LayerSummary& active = layers.at(layers.size() - 1 - activeIndex);
        layerNameEdit_->setText(active.name);
        layerVisibleCheckBox_->setChecked(active.visible);
        layerLockedCheckBox_->setChecked(active.locked);
        layerOpacitySlider_->setValue(static_cast<int>(std::round(active.opacity * 100.0)));
        layerBlendModeCombo_->setCurrentIndex(layerBlendModeCombo_->findData(static_cast<int>(active.blendMode)));
    }

    duplicateLayerButton_->setEnabled(activeIndex >= 0);
    removeLayerButton_->setEnabled(layers.size() > 1);
    moveLayerUpButton_->setEnabled(activeIndex >= 0 && activeIndex < layers.size() - 1);
    moveLayerDownButton_->setEnabled(activeIndex > 0);
    mergeDownButton_->setEnabled(canvasWidget_->canMergeActiveLayerDown());
    int visibleLayerCount = 0;
    for (const CanvasWidget::LayerSummary& summary : layers) {
        if (summary.visible) {
            ++visibleLayerCount;
        }
    }
    mergeVisibleButton_->setEnabled(visibleLayerCount > 1);
    clearLayerButton_->setEnabled(canvasWidget_->hasEditableActiveLayer());
    layerControlsUpdating_ = false;
}

void MainWindow::refreshLayerList() {
    const QSignalBlocker listBlocker(layerListWidget_);
    layerListWidget_->clear();
    const QString keyword = layerSearchEdit_->text().trimmed().toLower();
    const QVector<CanvasWidget::LayerSummary> layers = canvasWidget_->layerSummaries();
    const int totalLayers = layers.size();
    for (int displayIndex = 0; displayIndex < layers.size(); ++displayIndex) {
        const CanvasWidget::LayerSummary& summary = layers.at(displayIndex);
        if (!keyword.isEmpty() && !summary.name.toLower().contains(keyword)) {
            continue;
        }
        const int actualIndex = totalLayers - 1 - displayIndex;
        auto* item = new QListWidgetItem(QIcon(QPixmap::fromImage(summary.thumbnail)), QStringLiteral("%1  [%2 | %3]").arg(summary.name, summary.visible ? QStringLiteral("可见") : QStringLiteral("隐藏"), summary.locked ? QStringLiteral("锁定") : QStringLiteral("可编辑")), layerListWidget_);
        item->setData(Qt::UserRole, actualIndex);
        if (summary.active) {
            layerListWidget_->setCurrentItem(item);
        }
    }
}

void MainWindow::chooseBrushColor() {
    const QColor color = QColorDialog::getColor(canvasWidget_->brushColor(), this, QStringLiteral("选择画笔颜色"));
    if (color.isValid()) {
        canvasWidget_->setBrushColor(color);
    }
}

void MainWindow::chooseTextColor() {
    const QColor color = QColorDialog::getColor(canvasWidget_->textStyle().color, this, QStringLiteral("选择文字颜色"));
    if (!color.isValid()) {
        return;
    }
    CanvasWidget::TextStyleState style = canvasWidget_->textStyle();
    style.color = color;
    canvasWidget_->setTextStyle(style);
}

void MainWindow::showNewDocumentDialog() {
    QDialog dialog(this);
    dialog.setWindowTitle(QStringLiteral("新建文档"));
    auto* nameEdit = new QLineEdit(canvasWidget_->documentName(), &dialog);
    auto* widthSpin = new QSpinBox(&dialog);
    widthSpin->setRange(320, 6000);
    widthSpin->setValue(canvasWidget_->documentSize().width());
    auto* heightSpin = new QSpinBox(&dialog);
    heightSpin->setRange(240, 6000);
    heightSpin->setValue(canvasWidget_->documentSize().height());
    auto* colorButton = new QPushButton(&dialog);
    QColor selectedColor = canvasWidget_->backgroundColor();
    applyColorButtonStyle(colorButton, selectedColor);
    connect(colorButton, &QPushButton::clicked, &dialog, [&]() {
        const QColor color = QColorDialog::getColor(selectedColor, &dialog, QStringLiteral("选择背景颜色"));
        if (color.isValid()) {
            selectedColor = color;
            applyColorButtonStyle(colorButton, selectedColor);
        }
    });

    auto* form = new QFormLayout();
    form->addRow(QStringLiteral("文档名称"), nameEdit);
    form->addRow(QStringLiteral("宽度"), widthSpin);
    form->addRow(QStringLiteral("高度"), heightSpin);
    form->addRow(QStringLiteral("背景色"), colorButton);

    auto* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    auto* layout = new QVBoxLayout(&dialog);
    layout->addLayout(form);
    layout->addWidget(buttons);

    if (dialog.exec() == QDialog::Accepted) {
        canvasWidget_->createDocument(nameEdit->text(), widthSpin->value(), heightSpin->value(), selectedColor);
    }
}

void MainWindow::openProject() {
    const QString filePath = QFileDialog::getOpenFileName(this, QStringLiteral("打开绘图文件"), QString(), QStringLiteral("绘图文件 (*.dbp *.json *.png *.jpg *.jpeg *.webp *.bmp *.gif *.svg)"));
    if (filePath.isEmpty()) {
        return;
    }
    QString errorMessage;
    if (!canvasWidget_->openProjectFile(filePath, &errorMessage)) {
        QMessageBox::warning(this, QStringLiteral("打开失败"), errorMessage);
    }
}

void MainWindow::saveProject() {
    const QString filePath = QFileDialog::getSaveFileName(this, QStringLiteral("保存项目"), QStringLiteral("%1.dbp").arg(canvasWidget_->documentName()), QStringLiteral("绘图项目 (*.dbp)"));
    if (filePath.isEmpty()) {
        return;
    }
    QString errorMessage;
    if (!canvasWidget_->saveProjectFile(filePath, &errorMessage)) {
        QMessageBox::warning(this, QStringLiteral("保存失败"), errorMessage);
    }
}

void MainWindow::importImage() {
    const QString filePath = QFileDialog::getOpenFileName(this, QStringLiteral("导入图片"), QString(), QStringLiteral("图片文件 (*.png *.jpg *.jpeg *.webp *.bmp *.gif *.svg)"));
    if (filePath.isEmpty()) {
        return;
    }
    QString errorMessage;
    if (!canvasWidget_->importImageFile(filePath, &errorMessage)) {
        QMessageBox::warning(this, QStringLiteral("导入失败"), errorMessage);
    }
}

void MainWindow::exportPng() {
    const QString filePath = QFileDialog::getSaveFileName(this, QStringLiteral("导出 PNG"), QStringLiteral("%1.png").arg(canvasWidget_->documentName()), QStringLiteral("PNG 文件 (*.png)"));
    if (filePath.isEmpty()) {
        return;
    }
    QString errorMessage;
    if (!canvasWidget_->exportPng(filePath, &errorMessage)) {
        QMessageBox::warning(this, QStringLiteral("导出失败"), errorMessage);
    }
}

void MainWindow::exportSvg() {
    const QString filePath = QFileDialog::getSaveFileName(this, QStringLiteral("导出 SVG"), QStringLiteral("%1.svg").arg(canvasWidget_->documentName()), QStringLiteral("SVG 文件 (*.svg)"));
    if (filePath.isEmpty()) {
        return;
    }
    QString errorMessage;
    if (!canvasWidget_->exportSvg(filePath, &errorMessage)) {
        QMessageBox::warning(this, QStringLiteral("导出失败"), errorMessage);
    }
}

void MainWindow::showUsageDialog() {
    QMessageBox::information(this, QStringLiteral("使用提示"), QStringLiteral("桌面版现已完全使用原生 Qt 实现。\n\n1. 左侧工具栏切换工具。\n2. 右侧两个 Dock 控制颜色/笔刷/文字/图层。\n3. Ctrl+N/O/S/Z/Y 可继续使用。\n4. 复杂操作会自动进入历史，可直接撤销重做。"));
}

void MainWindow::showAboutDialog() {
    QMessageBox::about(this, QStringLiteral("关于 Drawing Board Pro Desktop"), QStringLiteral("Drawing Board Pro Desktop\n基于 Qt Widgets 原生实现，已不再依赖 WebEngine/Vue 作为桌面前端。"));
}
