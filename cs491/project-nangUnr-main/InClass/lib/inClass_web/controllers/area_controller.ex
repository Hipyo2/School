defmodule InClassWeb.AreaController do
  use InClassWeb, :controller

  alias InClass.Company
  alias InClass.Company.Area

  def index(conn, _params) do
    areas = Company.list_areas()
    render(conn, "index.html", areas: areas)
  end

  def new(conn, _params) do
    changeset = Company.change_area(%Area{})
    render(conn, "new.html", changeset: changeset)
  end

  def create(conn, %{"area" => area_params}) do
    case Company.create_area(area_params) do
      {:ok, area} ->
        conn
        |> put_flash(:info, "Area created successfully.")
        |> redirect(to: Routes.area_path(conn, :show, area))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    area = Company.get_area!(id)
    render(conn, "show.html", area: area)
  end

  def edit(conn, %{"id" => id}) do
    area = Company.get_area!(id)
    changeset = Company.change_area(area)
    render(conn, "edit.html", area: area, changeset: changeset)
  end

  def update(conn, %{"id" => id, "area" => area_params}) do
    area = Company.get_area!(id)

    case Company.update_area(area, area_params) do
      {:ok, area} ->
        conn
        |> put_flash(:info, "Area updated successfully.")
        |> redirect(to: Routes.area_path(conn, :show, area))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", area: area, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    area = Company.get_area!(id)
    {:ok, _area} = Company.delete_area(area)

    conn
    |> put_flash(:info, "Area deleted successfully.")
    |> redirect(to: Routes.area_path(conn, :index))
  end
end
