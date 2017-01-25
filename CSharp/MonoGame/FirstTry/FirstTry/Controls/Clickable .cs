using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Input.Touch;
using Microsoft.Xna.Framework.Input;

namespace FirstTry.Controls
{
    public class Clickable : DrawableGameComponent
    {

        #region Fields
        readonly Rectangle _rectangle;
        bool _wasPressed;
        bool _isPressed;
        bool _mouseOver;
        bool _objectCanBeClicked;

        public bool MouseOver
        {
            get
            {
                return _mouseOver;
            }
        }

        #region Protected accessors
        public bool IsPressed { get { return _isPressed; } }
        public bool IsClicked { get { return (_wasPressed == true) && (_isPressed == false); } }
        protected new Game1 Game
        {
            get
            {
                return (Game1)base.Game;
            }
        }

        protected Rectangle Rectangle { get { return _rectangle; } }

        #endregion
        #endregion

        #region Initialization
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="game">The Game oject</param>
        /// <param name="targetRectangle">Position of the component on the screen</param>
        public Clickable(Game1 game, Rectangle targetRectangle)
            : base(game)
        {
            
            _rectangle = targetRectangle;
        }
        #endregion

        #region Input handling
        /// <summary>
        /// Handles Input
        /// </summary>
        protected void HandleInput()
        {
            MouseState currentMouseState = Mouse.GetState();

            Rectangle cursorRect = new Rectangle((int)currentMouseState.Position.X - 5, (int)currentMouseState.Position.Y - 5,
                10, 10);

            bool intersection = _rectangle.Intersects(cursorRect);

            if (!intersection)
            {
                _mouseOver = false;
                _objectCanBeClicked = false;
                _isPressed = false;
                _wasPressed = false;
            }
            else
            {
                _mouseOver = true;
                _wasPressed = _isPressed;
            }

            if (currentMouseState.LeftButton == ButtonState.Released && intersection)
            {
                _objectCanBeClicked = true;
                _isPressed = false;
            }
            else if (currentMouseState.LeftButton == ButtonState.Pressed && _objectCanBeClicked)
            {
                _isPressed = true;
            }

        }
        #endregion
    }
}
