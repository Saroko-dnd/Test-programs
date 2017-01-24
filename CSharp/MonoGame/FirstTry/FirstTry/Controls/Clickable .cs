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
        readonly Rectangle rectangle;
        bool wasPressed;
        bool isPressed;
        bool mouseOver;
        bool objectCanBeClicked;

        public bool MouseOver
        {
            get
            {
                return mouseOver;
            }
        }

        #region Protected accessors
        public bool IsPressed { get { return isPressed; } }
        public bool IsClicked { get { return (wasPressed == true) && (isPressed == false); } }
        protected new Game1 Game
        {
            get
            {
                return (Game1)base.Game;
            }
        }

        protected Rectangle Rectangle { get { return rectangle; } }

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
            
            rectangle = targetRectangle;
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

            bool intersection = rectangle.Intersects(cursorRect);

            if (!intersection)
            {
                mouseOver = false;
                objectCanBeClicked = false;
                isPressed = false;
                wasPressed = false;
            }
            else
            {
                mouseOver = true;
                wasPressed = isPressed;
            }

            if (currentMouseState.LeftButton == ButtonState.Released && intersection)
            {
                objectCanBeClicked = true;
                isPressed = false;
            }
            else if (currentMouseState.LeftButton == ButtonState.Pressed && objectCanBeClicked)
            {
                isPressed = true;
            }

        }
        #endregion
    }
}
