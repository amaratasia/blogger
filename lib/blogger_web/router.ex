defmodule BloggerWeb.Router do
  use BloggerWeb, :router

  pipeline :browser do
    plug(:accepts, ["html"])
    plug(:fetch_session)
    plug(:fetch_flash)
    plug(:protect_from_forgery)
    plug(:put_secure_browser_headers)
  end

  pipeline :api do
    plug(:accepts, ["json"])

    resources("/posts", PostController, except: [:new, :edit])
  end

  scope "/", BloggerWeb do
    # Use the default browser stack
    pipe_through(:browser)

    get("/", PageController, :index)
  end

  # Other scopes may use custom stacks.
  # scope "/api", BloggerWeb do
  #   pipe_through :api
  # end
end
