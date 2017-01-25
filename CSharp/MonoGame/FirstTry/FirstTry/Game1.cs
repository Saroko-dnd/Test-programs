using FirstTry.Controls;
using FirstTry.GameObjects;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using System.Collections.Generic;

namespace FirstTry
{
    /// <summary>
    /// This is the main type for your game.
    /// </summary>
    public class Game1 : Game
    {
        public enum Algorithms { DecimalToBinary, Second };

        GraphicsDeviceManager _graphics;
        SpriteBatch _spriteBatch;
        Texture2D _testImage;
        Vector2 _test2dPosition;
        Vector2 _test2dTextPosition;
        Vector2 _test2dTextOrigin;

        SpriteFont _testSpriteFont;
        SpriteFont _spriteFontForMenuOptions;

        SelectorOfAlgorithms _currentGameContentAndLogic;

        bool _userDemandsExit;
        bool _gameWindowCanBeClosed;        

        public SpriteBatch SpriteBatch
        {
            get
            {
                return _spriteBatch;
            }

            private set
            {
                _spriteBatch = value;
            }
        }

        public SpriteFont TestSpriteFont
        {
            get
            {
                return _testSpriteFont;
            }

            set
            {
                _testSpriteFont = value;
            }
        }

        public Game1()
        {
            _currentGameContentAndLogic = new SelectorOfAlgorithms(this, "Fonts/SquareBlock", "Images/Button", new Rectangle(0, 0, 200, 50));
            _graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            this._graphics.PreferredBackBufferWidth = 1000;  // set this value to the desired width of your window
            this._graphics.PreferredBackBufferHeight = 800;   // set this value to the desired height of your window 
            this._graphics.ApplyChanges();
            
            this.IsMouseVisible = true;
            
            _test2dPosition = new Vector2(0,0);
            _test2dTextPosition = new Vector2(50,50);
            _test2dTextOrigin = new Vector2(0,0);

            this.Window.Title = "Algorithms";

            System.Windows.Forms.Form f = System.Windows.Forms.Form.FromHandle(Window.Handle) as System.Windows.Forms.Form;
            if (f != null)
            {
                f.FormClosing += gameFormClosing;
            }

            _currentGameContentAndLogic.Initialize();

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            _spriteBatch = new SpriteBatch(GraphicsDevice);

            _testImage = this.Content.Load<Texture2D>("Images/maxresdefault");
            TestSpriteFont = this.Content.Load<SpriteFont>("Fonts/TestSpriteFont");
            _spriteFontForMenuOptions = this.Content.Load<SpriteFont>("Fonts/SquareBlock");


            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// game-specific content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
            this.Content.Unload();
            base.UnloadContent();
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            if (_userDemandsExit)
            {
                _currentGameContentAndLogic.Dispose();
                _gameWindowCanBeClosed = true;
                Exit();
            }
            else
            {
                if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                    Exit();
                else if (Keyboard.GetState().IsKeyDown(Keys.Left))
                {
                    _test2dPosition.X -= 1;
                }
                else if (Keyboard.GetState().IsKeyDown(Keys.Right))
                {
                    _test2dPosition.X += 1;
                }
                else if (Keyboard.GetState().IsKeyDown(Keys.Up))
                {
                    _test2dPosition.Y -= 1;
                }
                else if (Keyboard.GetState().IsKeyDown(Keys.Down))
                {
                    _test2dPosition.Y += 1;
                }
            }

            _currentGameContentAndLogic.Update(gameTime);
            // TODO: Add your update logic here

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            _spriteBatch.Begin();
            _spriteBatch.Draw(_testImage, _test2dPosition, layerDepth: 1.0f);
            _spriteBatch.DrawString(TestSpriteFont, "Test text", _test2dTextPosition, Color.Blue, 0.0f, _test2dTextOrigin, 1.0f, SpriteEffects.None, 0.0f);
            _spriteBatch.End();

            _currentGameContentAndLogic.Draw(gameTime);

            // TODO: Add your drawing code here

            base.Draw(gameTime);
        }

        void gameFormClosing(object sender, System.Windows.Forms.FormClosingEventArgs e)
        {
            /*if (!_gameWindowCanBeClosed)
            {
                _userDemandsExit = true;
                e.Cancel = true;
            }*/
        }

        public new void Dispose()
        {
            int ggg = 9;
        }
    }
}
