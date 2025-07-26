import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class VisualNode extends StackPane {
    public VisualNode(String value) {
        Rectangle box = new Rectangle(80, 40);
        box.setArcWidth(10);
        box.setArcHeight(10);
        box.setFill(Color.LIGHTBLUE);
        box.setStroke(Color.DARKBLUE);

        Text text = new Text(value);
        text.setFont(Font.font(16));

        this.getChildren().addAll(box, text);
    }
}

