import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;
import javafx.geometry.*;
import javafx.scene.text.*;

public class Main extends Application {

    private boolean isStackMode = true;

    private StackManager stackManager = new StackManager();
    private QueueManager queueManager = new QueueManager();

    private int operationCount = 0;

    // Additional counters
    private int pushCount = 0;
    private int popCount = 0;
    private int enqueueCount = 0;
    private int dequeueCount = 0;

    private long lastOpTimeNano = 0;

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("OrderFlow: Stack and Queue Explorer");

        Label titleLabel = new Label("OrderFlow: Stack and Queue Explorer");
        titleLabel.setFont(Font.font("Arial", FontWeight.BOLD, 20));

        ToggleGroup modeToggle = new ToggleGroup();
        RadioButton stackRadio = new RadioButton("Stack");
        RadioButton queueRadio = new RadioButton("Queue");
        stackRadio.setToggleGroup(modeToggle);
        queueRadio.setToggleGroup(modeToggle);
        stackRadio.setSelected(true);

        HBox topBar = new HBox(20, titleLabel, stackRadio, queueRadio);
        topBar.setAlignment(Pos.CENTER);
        topBar.setPadding(new Insets(10));

        VBox stackBox = new VBox(10);
        stackBox.setAlignment(Pos.BOTTOM_CENTER);

        HBox queueBox = new HBox(10);
        queueBox.setAlignment(Pos.CENTER_LEFT);
        queueBox.setVisible(false);

        StackPane visualizationPane = new StackPane(stackBox, queueBox);
        visualizationPane.setPrefHeight(300);
        visualizationPane.setStyle("-fx-border-color: gray; -fx-background-color: #f0f0f0;");

        TextField inputField = new TextField();
        inputField.setPromptText("Enter a value");
        inputField.setPrefWidth(150);

        Button pushButton = new Button("Push");
        Button popButton = new Button("Pop");
        HBox stackButtons = new HBox(10, pushButton, popButton);
        stackButtons.setAlignment(Pos.CENTER);

        Button enqueueButton = new Button("Enqueue");
        Button dequeueButton = new Button("Dequeue");
        HBox queueButtons = new HBox(10, enqueueButton, dequeueButton);
        queueButtons.setAlignment(Pos.CENTER);
        queueButtons.setVisible(false);

        Label opCounterLabel = new Label("Operations: 0");
        Label complexityLabel = new Label(); // Updated dynamically

        updateComplexityLabel(complexityLabel); // Initial value

        VBox bottomPanel = new VBox(10, inputField, stackButtons, queueButtons, opCounterLabel, complexityLabel);
        bottomPanel.setAlignment(Pos.CENTER);
        bottomPanel.setPadding(new Insets(10));

        modeToggle.selectedToggleProperty().addListener((obs, oldToggle, newToggle) -> {
            isStackMode = (newToggle == stackRadio);
            stackButtons.setVisible(isStackMode);
            queueButtons.setVisible(!isStackMode);
            stackBox.setVisible(isStackMode);
            queueBox.setVisible(!isStackMode);
            resetOperationCount(opCounterLabel);
        });

        pushButton.setOnAction(e -> {
            String value = inputField.getText();
            if (!value.isEmpty()) {
                long start = System.nanoTime();
                stackManager.push(value);
                long end = System.nanoTime();

                stackBox.getChildren().add(0, new VisualNode(value));
                inputField.clear();
                pushCount++;
                lastOpTimeNano = end - start;
                updateOperationCount(opCounterLabel);
                updateComplexityLabel(complexityLabel);
                inputField.requestFocus();
            }
        });

        popButton.setOnAction(e -> {
            if (!stackManager.isEmpty()) {
                long start = System.nanoTime();
                stackManager.pop();
                long end = System.nanoTime();

                stackBox.getChildren().remove(0);
                popCount++;
                lastOpTimeNano = end - start;
                updateOperationCount(opCounterLabel);
                updateComplexityLabel(complexityLabel);
                inputField.requestFocus();
            }
        });

        enqueueButton.setOnAction(e -> {
            String value = inputField.getText();
            if (!value.isEmpty()) {
                long start = System.nanoTime();
                queueManager.enqueue(value);
                long end = System.nanoTime();

                queueBox.getChildren().add(new VisualNode(value));
                inputField.clear();
                enqueueCount++;
                lastOpTimeNano = end - start;
                updateOperationCount(opCounterLabel);
                updateComplexityLabel(complexityLabel);
                inputField.requestFocus();
            }
        });

        dequeueButton.setOnAction(e -> {
            if (!queueManager.isEmpty()) {
                long start = System.nanoTime();
                queueManager.dequeue();
                long end = System.nanoTime();

                queueBox.getChildren().remove(0);
                dequeueCount++;
                lastOpTimeNano = end - start;
                updateOperationCount(opCounterLabel);
                updateComplexityLabel(complexityLabel);
                inputField.requestFocus();
            }
        });

        BorderPane root = new BorderPane();
        root.setTop(topBar);
        root.setCenter(visualizationPane);
        root.setBottom(bottomPanel);

        Scene scene = new Scene(root, 600, 500);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void updateOperationCount(Label opCounterLabel) {
        operationCount++;
        opCounterLabel.setText("Operations: " + operationCount);
    }

    private void resetOperationCount(Label opCounterLabel) {
        operationCount = 0;
        pushCount = 0;
        popCount = 0;
        enqueueCount = 0;
        dequeueCount = 0;
        lastOpTimeNano = 0;
        opCounterLabel.setText("Operations: 0");
    }

    private void updateComplexityLabel(Label label) {
        int stackSize = stackManager.getSize();
        int queueSize = queueManager.getSize();
        int memoryEstimateBytes = (isStackMode ? stackSize : queueSize) * 16;
        double lastTimeMs = lastOpTimeNano / 1_000_000.0;

        label.setText(String.format(
                "Time: O(1), Space: O(n)\nPushes: %d | Pops: %d | Enqueues: %d | Dequeues: %d\nLast Op Time: %.4f ms | Memory: %d bytes",
                pushCount, popCount, enqueueCount, dequeueCount,
                lastTimeMs, memoryEstimateBytes
        ));
    }

    public static void main(String[] args) {
        launch(args);
    }
}
