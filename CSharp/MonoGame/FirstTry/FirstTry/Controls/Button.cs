using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
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

        public int ID { get; set; }
        string _assetName;
        Texture2D _texture;
        float _currentLayerDepth;
        Rectangle _usualRectangle;
        Rectangle _mouseOverRectangle;
        Rectangle _pressedRectangle;     
        States _currentStateOfButton = States.Usual;

        ContentManager _content;

        string _fontName;
        float _textXPosition;
        float _textYPosition;
        SpriteFont _currentSpriteFont;
        string _text = "Button";

        public enum States { Usual, MouseOver, Pressed };
        public event OnButtonClick OnClick;

        public string Text
        {
            get
            {
                return _text;
            }

            set
            {
                _text = value;
                if (_currentSpriteFont != null)
                {
                    _setTextPositions();
                }
            }
        }

        private void _setTextPositions()
        {
            Vector2 renderedTextSize = _currentSpriteFont.MeasureString(Text);
            _textXPosition = (Rectangle.X + (Rectangle.Width / 2)) - (renderedTextSize.X / 2);
            _textYPosition = (Rectangle.Y + (Rectangle.Height / 2)) - (renderedTextSize.Y / 2);
        }

        public SpriteFont CurrentSpriteFont
        {
            get
            {
                return _currentSpriteFont;
            }

            set
            {
                _currentSpriteFont = value;
            }
        }

        void LaunchOnClickEvent()
        {
            OnClick(this);
        }

        
        public Button(Game1 game, ContentManager content, string textureName,Rectangle sourceRectangleForUsualState, Rectangle sourceRectangleForMouseOverState, Rectangle sourceRectangleForPressedState, Rectangle targetRectangle, 
            float layerDepth, string fontName)
            : base(game, targetRectangle)
        {
            _assetName = textureName;
            _currentLayerDepth = layerDepth;
            _usualRectangle = sourceRectangleForUsualState;
            _mouseOverRectangle = sourceRectangleForMouseOverState;
            _pressedRectangle = sourceRectangleForPressedState;
            _content = content;
            _fontName = fontName;
        }

        protected override void LoadContent()
        {
            _texture = _content.Load<Texture2D>(_assetName);
            _currentSpriteFont = _content.Load<SpriteFont>(_fontName);

            if (_text != null)
            {
                _setTextPositions();
            }

            base.LoadContent();
        }

        public override void Update(GameTime gameTime)
        {
            HandleInput();
            if (IsPressed)
            {
                _currentStateOfButton = States.Pressed;
            }
            else if (MouseOver)
            {
                _currentStateOfButton = States.MouseOver;
            }
            else
            {
                _currentStateOfButton = States.Usual;
            }

            base.Update(gameTime);
        }

        public override void Draw(GameTime gameTime)
        {
            Game.SpriteBatch.Begin();
            if (_currentStateOfButton == States.Usual )
            {
                Game.SpriteBatch.Draw(_texture, sourceRectangle: _usualRectangle, destinationRectangle: Rectangle, layerDepth: _currentLayerDepth,
                    effects: SpriteEffects.FlipVertically | SpriteEffects.FlipHorizontally);
                Game.SpriteBatch.DrawString(_currentSpriteFont, _text, new Vector2(_textXPosition, _textYPosition), Color.Black, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            }
            else if (_currentStateOfButton == States.MouseOver)
            {
                Game.SpriteBatch.Draw(_texture, sourceRectangle: _mouseOverRectangle, destinationRectangle: Rectangle, layerDepth: _currentLayerDepth);
                Game.SpriteBatch.DrawString(_currentSpriteFont, _text, new Vector2(_textXPosition, _textYPosition), Color.Blue, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            }
            else if (_currentStateOfButton == States.Pressed)
            {
                Game.SpriteBatch.Draw(_texture, sourceRectangle: _pressedRectangle, destinationRectangle: Rectangle, layerDepth: _currentLayerDepth);
                Game.SpriteBatch.DrawString(_currentSpriteFont, _text, new Vector2(_textXPosition, _textYPosition + 5), Color.Blue, 0.0f, new Vector2(0, 0), 1.0f,
                    SpriteEffects.None, 0.0f);
            } 
            
            Game.SpriteBatch.End();
            base.Draw(gameTime);
        }

    }
}
