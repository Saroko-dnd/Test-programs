using FirstTry.Controls;
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

        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        Texture2D TestImage;
        Vector2 Test2dPosition;
        Vector2 Test2dTextPosition;
        Vector2 Test2dTextOrigin;

        SpriteFont testSpriteFont;
        SpriteFont spriteFontForMenuOptions;

        bool componentsEmpty = false;

        List<Button> ListOfButtons = new List<Button>();

        DrawableGameComponent CurrentGameContentAndLogic;       

        public SpriteBatch SpriteBatch
        {
            get
            {
                return spriteBatch;
            }

            private set
            {
                spriteBatch = value;
            }
        }

        public SpriteFont TestSpriteFont
        {
            get
            {
                return testSpriteFont;
            }

            set
            {
                testSpriteFont = value;
            }
        }

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
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
            this.graphics.PreferredBackBufferWidth = 1000;  // set this value to the desired width of your window
            this.graphics.PreferredBackBufferHeight = 800;   // set this value to the desired height of your window        
            this.graphics.ApplyChanges();
            
            this.IsMouseVisible = true;
            
            Test2dPosition = new Vector2(0,0);
            Test2dTextPosition = new Vector2(50,50);
            Test2dTextOrigin = new Vector2(0,0);

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            TestImage = this.Content.Load<Texture2D>("Images/maxresdefault");
            TestSpriteFont = this.Content.Load<SpriteFont>("Fonts/TestSpriteFont");
            spriteFontForMenuOptions = this.Content.Load<SpriteFont>("Fonts/SquareBlock");

            ListOfButtons.Add(new Button(this, "Images/Button", new Rectangle(2, 134, 202, 50), new Rectangle(2, 6, 202, 50), new Rectangle(2, 70, 202, 50), new Rectangle(0, 0, 200, 50), 0.9f, 
                spriteFontForMenuOptions){Text = "Decimal to Binary" });
            foreach (Button FoundComponent in ListOfButtons)
            {
                FoundComponent.Initialize();
            }
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
            if (gameTime.TotalGameTime.Seconds > 5 && !componentsEmpty)
            {
                Components.Remove(Components[0]);
                componentsEmpty = true;
            }

            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || Keyboard.GetState().IsKeyDown(Keys.Escape))
                Exit();
            else if (Keyboard.GetState().IsKeyDown(Keys.Left))
            {
                Test2dPosition.X -= 1;
            }
            else if (Keyboard.GetState().IsKeyDown(Keys.Right))
            {
                Test2dPosition.X += 1;
            }
            else if (Keyboard.GetState().IsKeyDown(Keys.Up))
            {
                Test2dPosition.Y -= 1;
            }
            else if (Keyboard.GetState().IsKeyDown(Keys.Down))
            {
                Test2dPosition.Y += 1;
            }
            foreach (DrawableGameComponent FoundComponent in ListOfButtons)
            {
                FoundComponent.Update(gameTime);
            }
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

            spriteBatch.Begin();
            spriteBatch.Draw(TestImage, Test2dPosition, layerDepth: 1.0f);
            spriteBatch.DrawString(TestSpriteFont, "Test text", Test2dTextPosition, Color.Blue, 0.0f, Test2dTextOrigin, 1.0f, SpriteEffects.None, 0.0f);
            spriteBatch.End();
            foreach (DrawableGameComponent FoundComponent in ListOfButtons)
            {
                FoundComponent.Draw(gameTime);
            }
            // TODO: Add your drawing code here

            base.Draw(gameTime);
        }
    }
}
