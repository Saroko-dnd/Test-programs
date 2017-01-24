using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstTry.Controls
{
    public delegate void OnButtonClick(Button sender);

    public class Button : Clickable
    {
        public enum States { Usual, MouseOver, Pressed };
        string assetName;
        Texture2D texture;
        float currentLayerDepth;
        Rectangle usualRectangle;
        Rectangle mouseOverRectangle;
        Rectangle pressedRectangle;     
        States currentStateOfButton = States.Usual;
        public event OnButtonClick OnClick;

        float textXPosition;
        float textYPosition;
        SpriteFont currentSpriteFont;
        string text = "Button";

        public string Text
        {
            get
            {
                return text;
            }

            set
            {
                text = value;
                Vector2 renderedTextSize = currentSpriteFont.MeasureString(Text);
                textXPosition = (Rectangle.X + (Rectangle.Width / 2)) - (renderedTextSize.X / 2);
                textYPosition = (Rectangle.Y + (Rectangle.Height / 2)) - (renderedTextSize.Y / 2);
            }
        }

        public SpriteFont CurrentSpriteFont
        {
            get
            {
                return currentSpriteFont;
            }

            set
            {
                currentSpriteFont = value;
            }
        }

        void LaunchOnClickEvent()
        {
            OnClick(this);
        }

        public Button(Game1 game, string textureName,Rectangle sourceRectangleForUsualState, Rectangle sourceRectangleForMouseOverState, Rectangle sourceRectangleForPressedState, Rectangle targetRectangle, 
            float layerDepth, SpriteFont font)
            : base(game, targetRectangle)
        {
            assetName = textureName;
            currentLayerDepth = layerDepth;
            usualRectangle = sourceRectangleForUsualState;
            mouseOverRectangle = sourceRectangleForMouseOverState;
            pressedRectangle = sourceRectangleForPressedState;
            currentSpriteFont = font;
        }

        protected override void LoadContent()
        {
            texture = Game.Content.Load<Texture2D>(assetName);
            base.LoadContent();
        }

        public override void Update(GameTime gameTime)
        {
            HandleInput();
            if (IsPressed)
            {
                currentStateOfButton = States.Pressed;
            }
            else if (MouseOver)
            {
                currentStateOfButton = States.MouseOver;
            }
            else
            {
                currentStateOfButton = States.Usual;
            }

            base.Update(gameTime);
        }

        public override void Draw(GameTime gameTime)
        {
            Game.SpriteBatch.Begin();
            if (currentStateOfButton == States.Usual )
            {
                Game.SpriteBatch.Draw(texture, sourceRectangle: usualRectangle, destinationRectangle: Rectangle, layerDepth: currentLayerDepth,
                    effects: SpriteEffects.FlipVertically | SpriteEffects.FlipHorizontally);
                Game.SpriteBatch.DrawString(currentSpriteFont, text, new Vector2(textXPosition, textYPosition), Color.Black, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            }
            else if (currentStateOfButton == States.MouseOver)
            {
                Game.SpriteBatch.Draw(texture, sourceRectangle: mouseOverRectangle, destinationRectangle: Rectangle, layerDepth: currentLayerDepth);
                Game.SpriteBatch.DrawString(currentSpriteFont, text, new Vector2(textXPosition, textYPosition), Color.Blue, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            }
            else if (currentStateOfButton == States.Pressed)
            {
                Game.SpriteBatch.Draw(texture, sourceRectangle: pressedRectangle, destinationRectangle: Rectangle, layerDepth: currentLayerDepth);
                Game.SpriteBatch.DrawString(currentSpriteFont, text, new Vector2(textXPosition, textYPosition + 5), Color.Blue, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            } 
            
            Game.SpriteBatch.End();
            base.Draw(gameTime);
        }

        public new void Dispose()
        {
            int ggg = 9;
        }
    }
}
